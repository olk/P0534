bool data_available( continuation const& c) noexcept;

template< typename Arg >
typename Arg transfer_data( continuation & c);

template< typename ... Arg >
typename std::tuple< Arg ... > transfer_data( continuation & c);

template< typename Fn, typename ... Arg >
continuation callcc( Fn && fn, Arg ... arg);

template< typename StackAlloc, typename Fn, typename ... Arg >
continuation callcc( std::allocator_arg_t, StackAlloc salloc, Fn && fn, Arg ... arg);

template< typename StackAlloc, typename Fn, typename ... Arg >
continuation callcc( std::allocator_arg_t, preallocated palloc, StackAlloc salloc, Fn && fn, Arg ... arg);

template< typename ... Arg >
continuation resume( continuation && c, Arg ... arg);

template< typename Fn, typename ... Arg >
continuation resume( continuation && c, exec_ontop_arg_t, Fn && fn, Arg ... arg);

void swap( continuation & l, continuation & r) noexcept;
