#include"../src/Gauss_zedel.h"
#include<iostream>
#include <gtest/gtest.h>

TEST(matrix, values){
    std::vector<double> values{1, 2, 4, 2, 6};
    std::vector<int> cols{0, 1, 1, 1, 2};
    std::vector<int> rows{0, 2, 3, 5};

    std::vector<double> b{1, 2, 3};

    CSR<double> matrix = CSR<double>(values,cols,rows);

    std::vector<double> res;
    res = Zedel(matrix,b,0.1); // here "free() invalid pointer" error
}

//==13381== Conditional jump or move depends on uninitialised value(s)
//==13381==    at 0x114BC3: std::_Vector_base<double, std::allocator<double> >::_M_deallocate(double*, unsigned long) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x113E03: std::_Vector_base<double, std::allocator<double> >::~_Vector_base() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x113AFE: std::vector<double, std::allocator<double> >::~vector() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x112F2A: matrix_values_Test::TestBody() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x156907: void testing::internal::HandleSehExceptionsInMethodIfSupported<testing::Test, void>(testing::Test*, void (testing::Test::*)(), char const*) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x14ECA6: void testing::internal::HandleExceptionsInMethodIfSupported<testing::Test, void>(testing::Test*, void (testing::Test::*)(), char const*) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x12A003: testing::Test::Run() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x12AAD2: testing::TestInfo::Run() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x12B408: testing::TestSuite::Run() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x13B236: testing::internal::UnitTestImpl::RunAllTests() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x157D9D: bool testing::internal::HandleSehExceptionsInMethodIfSupported<testing::internal::UnitTestImpl, bool>(testing::internal::UnitTestImpl*, bool (testing::internal::UnitTestImpl::*)(), char const*) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x14FDA2: bool testing::internal::HandleExceptionsInMethodIfSupported<testing::internal::UnitTestImpl, bool>(testing::internal::UnitTestImpl*, bool (testing::internal::UnitTestImpl::*)(), char const*) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381== 
//==13381== Conditional jump or move depends on uninitialised value(s)
//==13381==    at 0x483CF75: operator delete(void*) (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
//==13381==    by 0x116509: __gnu_cxx::new_allocator<double>::deallocate(double*, unsigned long) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x115A49: std::allocator_traits<std::allocator<double> >::deallocate(std::allocator<double>&, double*, unsigned long) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x114BDB: std::_Vector_base<double, std::allocator<double> >::_M_deallocate(double*, unsigned long) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x113E03: std::_Vector_base<double, std::allocator<double> >::~_Vector_base() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x113AFE: std::vector<double, std::allocator<double> >::~vector() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x112F2A: matrix_values_Test::TestBody() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x156907: void testing::internal::HandleSehExceptionsInMethodIfSupported<testing::Test, void>(testing::Test*, void (testing::Test::*)(), char const*) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x14ECA6: void testing::internal::HandleExceptionsInMethodIfSupported<testing::Test, void>(testing::Test*, void (testing::Test::*)(), char const*) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x12A003: testing::Test::Run() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x12AAD2: testing::TestInfo::Run() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x12B408: testing::TestSuite::Run() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381== 
//==13381== Invalid free() / delete / delete[] / realloc()
//==13381==    at 0x483CFBF: operator delete(void*) (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
//==13381==    by 0x116509: __gnu_cxx::new_allocator<double>::deallocate(double*, unsigned long) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x115A49: std::allocator_traits<std::allocator<double> >::deallocate(std::allocator<double>&, double*, unsigned long) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x114BDB: std::_Vector_base<double, std::allocator<double> >::_M_deallocate(double*, unsigned long) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x113E03: std::_Vector_base<double, std::allocator<double> >::~_Vector_base() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x113AFE: std::vector<double, std::allocator<double> >::~vector() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x112F2A: matrix_values_Test::TestBody() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x156907: void testing::internal::HandleSehExceptionsInMethodIfSupported<testing::Test, void>(testing::Test*, void (testing::Test::*)(), char const*) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x14ECA6: void testing::internal::HandleExceptionsInMethodIfSupported<testing::Test, void>(testing::Test*, void (testing::Test::*)(), char const*) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x12A003: testing::Test::Run() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x12AAD2: testing::TestInfo::Run() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==    by 0x12B408: testing::TestSuite::Run() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_gauss_zedel)
//==13381==  Address 0x1ffefff920 is on thread 1's stack
//==13381==  in frame #9, created by testing::Test::Run() (???:)
//==13381== 



//total heap usage: 201 allocs, 202 frees, 113,764 bytes allocated
//ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)