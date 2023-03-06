.PHONY: all clean

all: 00_enumerate_cpu 00_enumerate_cuda

clean:
	rm -f 00_enumerate_cpu 00_enumerate_cuda

BOOST_BASE  ?= /afs/hep.wisc.edu/home/abocci/public/boost
ALPAKA_BASE ?= $(HOME)/private/alpaka/include

00_enumerate_cpu: 00_enumerate.cc
	g++ -std=c++17 -O2 -g -DALPAKA_ACC_CPU_B_SEQ_T_SEQ_ENABLED -I$(BOOST_BASE)/include -I$(ALPAKA_BASE)/include 00_enumerate.cc -o 00_enumerate_cpu

00_enumerate_cuda: 00_enumerate.cc
	nvcc -x cu -std=c++17 -O2 -g --expt-relaxed-constexpr -DALPAKA_ACC_GPU_CUDA_ENABLED -I$(BOOST_BASE)/include -I$(ALPAKA_BASE)/include 00_enumerate.cc -o 00_enumerate_cuda
