#pragma once
#include <utility>

template<typename... Args>
class Tuple;

template<typename Cur, typename... Others>
class Tuple<Cur, Others...> : private Tuple<Others...>
	{
	public:
		Cur m_cur;

	public:
		Tuple(const Cur& cur, const Others&... others) : Tuple<Others...>(others...), m_cur(cur)
			{}

		Tuple(Cur&& cur, Others&&... others) : Tuple<Others...>(std::move(others)...), m_cur(std::move(cur))
			{}

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
		constexpr auto& get() const
			{
			static_assert(false, "Out of range!");
			}
	};

