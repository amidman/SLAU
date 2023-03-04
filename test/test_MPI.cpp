#include<vector>
#include"../src/MPI.h"
#include <gtest/gtest.h>
#include<iostream>

TEST(MPI,test){
    std::cout<<"gfds";

    std::vector<double> values{1, 2, 4, 2, 6};
    std::vector<int> cols{0, 1, 1, 1, 2};
    std::vector<int> rows{0, 2, 3, 5};

    std::vector<double> b{1, 2, 3};

    CSR<double> matrix = CSR<double>(values,cols, rows);
    std::cout<<"gfds";
    std::vector<double> res;
    res = MPI(matrix,b,0.01,0.01); // here "free() invalid pointer" error
}

//==13572== Conditional jump or move depends on uninitialised value(s)
//==13572==    at 0x114BEB: std::_Vector_base<double, std::allocator<double> >::_M_deallocate(double*, unsigned long) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x113E2B: std::_Vector_base<double, std::allocator<double> >::~_Vector_base() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x113B26: std::vector<double, std::allocator<double> >::~vector() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x112F46: MPI_test_Test::TestBody() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x15692F: void testing::internal::HandleSehExceptionsInMethodIfSupported<testing::Test, void>(testing::Test*, void (testing::Test::*)(), char const*) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x14ECCE: void testing::internal::HandleExceptionsInMethodIfSupported<testing::Test, void>(testing::Test*, void (testing::Test::*)(), char const*) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x12A02B: testing::Test::Run() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x12AAFA: testing::TestInfo::Run() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x12B430: testing::TestSuite::Run() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x13B25E: testing::internal::UnitTestImpl::RunAllTests() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x157DC5: bool testing::internal::HandleSehExceptionsInMethodIfSupported<testing::internal::UnitTestImpl, bool>(testing::internal::UnitTestImpl*, bool (testing::internal::UnitTestImpl::*)(), char const*) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x14FDCA: bool testing::internal::HandleExceptionsInMethodIfSupported<testing::internal::UnitTestImpl, bool>(testing::internal::UnitTestImpl*, bool (testing::internal::UnitTestImpl::*)(), char const*) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572== 
//==13572== Conditional jump or move depends on uninitialised value(s)
//==13572==    at 0x483CF75: operator delete(void*) (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
//==13572==    by 0x116531: __gnu_cxx::new_allocator<double>::deallocate(double*, unsigned long) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x115A71: std::allocator_traits<std::allocator<double> >::deallocate(std::allocator<double>&, double*, unsigned long) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x114C03: std::_Vector_base<double, std::allocator<double> >::_M_deallocate(double*, unsigned long) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x113E2B: std::_Vector_base<double, std::allocator<double> >::~_Vector_base() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x113B26: std::vector<double, std::allocator<double> >::~vector() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x112F46: MPI_test_Test::TestBody() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x15692F: void testing::internal::HandleSehExceptionsInMethodIfSupported<testing::Test, void>(testing::Test*, void (testing::Test::*)(), char const*) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x14ECCE: void testing::internal::HandleExceptionsInMethodIfSupported<testing::Test, void>(testing::Test*, void (testing::Test::*)(), char const*) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x12A02B: testing::Test::Run() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x12AAFA: testing::TestInfo::Run() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x12B430: testing::TestSuite::Run() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572== 
//==13572== Invalid free() / delete / delete[] / realloc()
//==13572==    at 0x483CFBF: operator delete(void*) (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
//==13572==    by 0x116531: __gnu_cxx::new_allocator<double>::deallocate(double*, unsigned long) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x115A71: std::allocator_traits<std::allocator<double> >::deallocate(std::allocator<double>&, double*, unsigned long) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x114C03: std::_Vector_base<double, std::allocator<double> >::_M_deallocate(double*, unsigned long) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x113E2B: std::_Vector_base<double, std::allocator<double> >::~_Vector_base() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x113B26: std::vector<double, std::allocator<double> >::~vector() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x112F46: MPI_test_Test::TestBody() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x15692F: void testing::internal::HandleSehExceptionsInMethodIfSupported<testing::Test, void>(testing::Test*, void (testing::Test::*)(), char const*) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x14ECCE: void testing::internal::HandleExceptionsInMethodIfSupported<testing::Test, void>(testing::Test*, void (testing::Test::*)(), char const*) (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x12A02B: testing::Test::Run() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x12AAFA: testing::TestInfo::Run() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==    by 0x12B430: testing::TestSuite::Run() (in /home/amid/vs code/c++/SLAU/SLAU/test/run_test_MPI)
//==13572==  Address 0x1ffefff930 is on thread 1's stack
//==13572==  in frame #9, created by testing::Test::Run() (???:)
//==13572== 

//total heap usage: 201 allocs, 202 frees, 113,764 bytes allocated
//ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)