#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import multiprocessing

usage = 'python heat_cpu.py <process_num>'

def worker():
    try:
        while True:
            pass
    except:
        pass

def heat(proc_num):
    for i in range(proc_num):
        p = multiprocessing.Process(target=worker, args=(), daemon=True)
        p.start()
    try:
        while True:
            pass
    except KeyboardInterrupt:
        print("\nTerminating by user")

if __name__ == "__main__":
    try:
        proc_num = int(sys.argv[1])
    except:
        print(usage)
        sys.exit(1)
    heat(proc_num)
