#!/usr/bin/env python3

executable = "./nanotekspice"
invalids = "tests/invalids/"
import os
import subprocess
import signal
from time import time

# ANSI escape codes for colors
RED = "\033[31m"
GREEN = "\033[32m"
RESET = "\033[0m"

def get_files_names():
    files = os.listdir(invalids)
    return files

files = get_files_names()
for file in files:
    print(f"Testing {file}...")
    try:
        start_time = time()
        process = subprocess.Popen([executable, invalids + file], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        while True:
            if process.poll() is not None:
                break
            if time() - start_time > 1:
                process.send_signal(signal.SIGINT)
                print(RED + "Test failed due to timeout when testing " + file + RESET)
                break
        out, err = process.communicate()
        out = out.decode("utf-8")
        err = err.decode("utf-8")
        if process.returncode == 84 and err:
            print(GREEN + "Test passed" + RESET)
        else:
            print(RED + "Test failed" + RESET)
            exit(1)
    except Exception as e:
        print(RED + "Test failed due to error: " + str(e) + RESET)
    print("")
