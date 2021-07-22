#pragma once
#include <utility>

template<typename... Args>
class Tuple;

template<typename Cur, typename... Others>
class Tuple<Cur, Others...> : private Tuple<Others...>
	{
	public:
		Cur m_cur{};

		constexpr Tuple() noexcept = default;

		constexpr Tuple(Cur&& cur, Others&&... others) : Tuple<Others...>(std::forward<Others>(others)...), m_cur(std::forward<Cur>(cur))
			{}

		auto& operator=(const Tuple& tup)
			{
			m_cur = tup.m_cur;
			Tuple<Others...>::template operator=(static_cast<const Tuple<Others...>&>(tup));
			return *this;
			}

		auto& operator=(Tuple&& tup)
			{
			m_cur = std::move(tup.m_cur);
			Tuple<Others...>::template operator=(static_cast<Tuple<Others...>&&>(tup));
			return *this;
			}

		template<size_t N>
		constexpr auto& get()
			{
			return Tuple<Others...>::template get<N - 1>();
			}

		template<>
		constexpr auto& get<0u>()
			{
			return m_cur;
			}
		
		template<size_t N>
		constexpr const auto& get() const
			{
			return Tuple<Others...>::template get<N - 1>();
			}

		template<>
		constexpr const auto& get<0u>() const
			{
			return m_cur;
			}
	};

template<>
class Tuple<>
	{
	public:
		template<size_t N>
		constexpr const auto& get() const = delete;
	};

template<typename... Args>
Tuple(Args&&... args) -> Tuple<Args...>;

template< class... Types >
struct std::tuple_size< Tuple<Types...> >
	: std::integral_constant<std::size_t, sizeof...(Types)>
	{};

template< std::size_t I, class Head, class... Tail >
struct std::tuple_element<I, Tuple<Head, Tail...>>
	: std::tuple_element<I - 1, Tuple<Tail...>>
	{};

template< class Head, class... Tail >
struct std::tuple_element<0, Tuple<Head, Tail...>>
	{
	using type = Head;
	};