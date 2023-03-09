/*
 * g++ -std=c++17 -O2 -g -DALPAKA_ACC_CPU_B_SEQ_T_SEQ_ENABLED -I$BOOST_BASE/include -I$ALPAKA_BASE/include 00_enumerate.cc -o 00_enumerate_cpu
 * nvcc -x cu -std=c++17 -O2 -g --expt-relaxed-constexpr -DALPAKA_ACC_GPU_CUDA_ENABLED -I$BOOST_BASE/include -I$ALPAKA_BASE/include 00_enumerate.cc -o 00_enumerate_cuda
 */

#include <iostream>
#include <vector>

#include <alpaka/alpaka.hpp>

#include "config.h"

int main() {
  // the host abstraction always has a single device
  Host host = alpaka::getDevByIdx<HostPlatform>(0u);

  std::cout << "Host platform: " << alpaka::core::demangled<HostPlatform> << '\n';
  std::cout << "Found 1 device:\n";
  std::cout << "  - " << alpaka::getName(host) << '\n';
  std::cout << std::endl;

  // get all the devices on the accelerator platform
  std::vector<Device> devices = alpaka::getDevs<Platform>();

  std::cout << "Accelerator platform: " << alpaka::core::demangled<Platform> << '\n';
  std::cout << "Found " << devices.size() << " device(s):\n";
  for (auto const& device : devices)
    std::cout << "  - " << alpaka::getName(device) << '\n';
  std::cout << std::endl;
}
