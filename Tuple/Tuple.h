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
		auto& get()
			{
			return static_cast<Tuple<Others...>&>(*this).get<N - 1>();
			}

		template<>
		auto& get<0u>()
			{
			return m_cur;
			}
		
		template<size_t N>
		const auto& get() const
			{
			return static_cast<Tuple<Others...>&>(*this).get<N - 1>();
			}

		template<>
		const auto& get<0u>() const
			{
			return m_cur;
			}
	};

template<>
class Tuple<>
	{
	public:
		template<size_t N>
		auto& get() const
			{
			static_assert(false, "Out of range!");
			}
	};

