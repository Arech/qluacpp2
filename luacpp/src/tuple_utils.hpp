#pragma once

#include <cstddef>
#include <tuple>
#include <type_traits>
#include <utility>

namespace lua {
  template <typename... X>
  struct tuple_tail_type;

  template <typename head_t>
  struct tuple_tail_type<std::tuple<head_t>> {
    typedef std::tuple<> type;
  };

  template <typename head_t, typename... tail_t>
  struct tuple_tail_type<std::tuple<head_t, tail_t...> > {
    typedef std::tuple<tail_t...> type;
  };

  // Credits: http://stackoverflow.com/a/12650100
  
  template<size_t N>
  struct Apply {
    template<typename F, typename T, typename... A>
    static inline auto apply_tuple(F && f, T && t, A &&... a)
      -> decltype(Apply<N-1>::apply_tuple(
                                    ::std::forward<F>(f), ::std::forward<T>(t),
                                    ::std::get<N-1>(::std::forward<T>(t)), ::std::forward<A>(a)...
                                    ))
    {
      return Apply<N-1>::apply_tuple(::std::forward<F>(f), ::std::forward<T>(t),
                               ::std::get<N-1>(::std::forward<T>(t)), ::std::forward<A>(a)...
                               );
    }
  };

  template<>
  struct Apply<0> {
    template<typename F, typename T, typename... A>
    static inline auto apply_tuple(F && f, T &&, A &&... a)
      -> decltype(::std::forward<F>(f)(::std::forward<A>(a)...))
    {
      return ::std::forward<F>(f)(::std::forward<A>(a)...);
    }
  };

  template<typename F, typename T>
  inline auto apply_tuple(F && f, T && t)
    -> decltype(Apply< ::std::tuple_size<
                typename ::std::decay<T>::type
                >::value>::apply_tuple(::std::forward<F>(f), ::std::forward<T>(t)))
  {
    return Apply< ::std::tuple_size<
      typename ::std::decay<T>::type
      >::value>::apply_tuple(::std::forward<F>(f), ::std::forward<T>(t));
  }  
} 
