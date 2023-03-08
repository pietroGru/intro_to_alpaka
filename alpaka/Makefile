.PHONY: all clean

TARGETS := 00_enumerate_cpu 00_enumerate_cuda 01_blocking_queue_cpu 02_nonblocking_queue_cpu 03_memory_cpu 03_memory_cuda

all: $(TARGETS)

clean:
	rm -f $(TARGETS)

CUDA_BASE   ?= /usr/local/cuda
BOOST_BASE  ?= /afs/hep.wisc.edu/home/abocci/public/boost
ALPAKA_BASE ?= /afs/hep.wisc.edu/home/abocci/public/alpaka

CXX  := g++
NVCC := $(CUDA_BASE)/bin/nvcc

CXXFLAGS       := -std=c++17 -O2 -g -I$(BOOST_BASE)/include -I$(ALPAKA_BASE)/include
CXX_HOST_FLAGS := -pthread
CXX_CUDA_FLAGS := --expt-relaxed-constexpr

%_cpu: %.cc
	$(CXX) $(CXXFLAGS) $(CXX_HOST_FLAGS) -DALPAKA_ACC_CPU_B_SEQ_T_SEQ_ENABLED $< -o $@

%_cuda: %.cc
	$(NVCC) -x cu -ccbin $(CXX) $(CXXFLAGS) $(CXX_CUDA_FLAGS) -Xcompiler '$(CXX_HOST_FLAGS)' -DALPAKA_ACC_GPU_CUDA_ENABLED $< -o $@

