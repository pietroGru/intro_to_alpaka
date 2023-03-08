/*
 * g++ -std=c++17 -O2 -g -DALPAKA_ACC_CPU_B_SEQ_T_SEQ_ENABLED -I$BOOST_BASE/include -I$ALPAKA_BASE/include 02_nonblocking_queue.cc -o 02_nonblocking_queue_cpu
 * nvcc -x cu -std=c++17 -O2 -g --expt-relaxed-constexpr -DALPAKA_ACC_GPU_CUDA_ENABLED -I$BOOST_BASE/include -I$ALPAKA_BASE/include 02_nonblocking_queue.cc -o 02_nonblocking_queue_cuda
 */

#include <chrono>
#include <iostream>
#include <thread>

#include <alpaka/alpaka.hpp>

#include "config.h"

int main() {
  // the host abstraction always has a single device
  Host host = alpaka::getDevByIdx<HostPlatform>(0u);

  std::cout << "Host platform: " << alpaka::core::demangled<HostPlatform> << '\n';
  std::cout << "Found 1 device:\n";
  std::cout << "  - " << alpaka::getName(host) << '\n';
  std::cout << std::endl;

  // create a non-blocking host queue and submit some work to it
  alpaka::Queue<Host, alpaka::NonBlocking> queue{host};

  std::cout << "Enqueue some work\n";
  alpaka::enqueue(queue, []() noexcept {
    std::cout << "  - host task running...\n";
    std::this_thread::sleep_for(std::chrono::seconds(5u));
    std::cout << "  - host task complete\n";
  });

  // wait for the work to complete
  std::cout << "Wait for the enqueue work to complete...\n";
  alpaka::wait(queue);
  std::cout << "All work has completed\n";
}
