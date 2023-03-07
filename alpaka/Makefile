.PHONY: all clean

TARGETS := 00_enumerate_cpu 00_enumerate_cuda 01_blocking_queue_cpu 02_nonblocking_queue_cpu

all: $(TARGETS)

clean:
	rm -f $(TARGETS)

BOOST_BASE  ?= /afs/hep.wisc.edu/home/abocci/public/boost
ALPAKA_BASE ?= /afs/hep.wisc.edu/home/abocci/public/alpaka

00_enumerate_cpu: 00_enumerate.cc
	g++ -std=c++17 -O2 -g -DALPAKA_ACC_CPU_B_SEQ_T_SEQ_ENABLED -I$(BOOST_BASE)/include -I$(ALPAKA_BASE)/include -pthread $< -o $@

00_enumerate_cuda: 00_enumerate.cc
	nvcc -x cu -std=c++17 -O2 -g --expt-relaxed-constexpr -DALPAKA_ACC_GPU_CUDA_ENABLED -I$(BOOST_BASE)/include -I$(ALPAKA_BASE)/include -Xcompiler -pthread $< -o $@

01_blocking_queue_cpu: 01_blocking_queue.cc
	g++ -std=c++17 -O2 -g -DALPAKA_ACC_CPU_B_SEQ_T_SEQ_ENABLED -I$(BOOST_BASE)/include -I$(ALPAKA_BASE)/include -pthread $< -o $@

02_nonblocking_queue_cpu: 02_nonblocking_queue.cc
	g++ -std=c++17 -O2 -g -DALPAKA_ACC_CPU_B_SEQ_T_SEQ_ENABLED -I$(BOOST_BASE)/include -I$(ALPAKA_BASE)/include -pthread $< -o $@

