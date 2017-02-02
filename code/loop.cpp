std::continuation foo(std::continuation && c1) {
    while (c1) {
        std::cout << "foo\n";
        c1= // (e)
           c1(); // (b)
    }
    return std::move(c1);
}

std::continuation c2= // (c)
                     std::callcc(foo); // (a)
while (c2) {
    std::cout << "bar\n";
    c2= // (f)
       c2(); // (d)
}

output:
    foo
    bar
    ...
