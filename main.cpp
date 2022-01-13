#include <QCoreApplication>
#include <iostream>

template < int N >
struct Factorial
{
    static const int result = N * Factorial< N - 1 >::result;
};

template <>
struct Factorial< 0 >
{
    static const int result = 1;
};

constexpr unsigned fact( unsigned N )
{
    return ( N == 0 ) ? 1 : N * fact( N - 1 );
}

constexpr unsigned fib( unsigned N )
{
    return ( N < 2 ) ? 1 : fib( N - 2 ) + fib( N - 1 );
}

template < unsigned N >
constexpr unsigned fib2 = fib2< N - 2 > + fib2< N - 1 >;

template <>
constexpr unsigned fib2< 0 > = 1;

template <>
constexpr unsigned fib2< 1 > = 1;

struct nil
{
};

template < class H, class T = nil >
struct cons
{
    typedef T Tail;
    typedef H Head;
    typedef cons< int, cons< std::string, cons< double, cons< float > > > > TypeList;
};

template < class TL >
void print()
{
    std::cout << typeid( typename TL::Head ).name() << std::endl;
    print< typename TL::Tail >();
}

template <>
void print< nil >()
{
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << Factorial< 5 >::result << std::endl;
    std::cout << fact( 10 ) << std::endl;

    std::cout << fib( 10 ) << std::endl;
    std::cout << fib2< 10 > << std::endl;

    return a.exec();
}
