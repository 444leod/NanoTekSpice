##
## EPITECH PROJECT, 2024
## NanoTekSpice
## File description:
## tester
##

executable = "./nanotekspice"
#retrieve all files names of the directory
import os
import subprocess
import signal
from colorama import Fore, Style
from time import time

def get_files_names():
    files = os.listdir("ressources/NanoTekSpice/tests/circuits/invalids/")
    return files

files = get_files_names()
for file in files:
    print(f"Testing {file}...")
    try:
        start_time = time()
        process = subprocess.Popen([executable, "ressources/NanoTekSpice/tests/circuits/invalids/" + file], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        while True:
            if process.poll() is not None:  # Process has terminated
                break
            if time() - start_time > 1:  # 1 second has passed
                process.send_signal(signal.SIGINT)
                print(Fore.RED + "Test failed due to timeout when testing " + file + Style.RESET_ALL)
                break
        out, err = process.communicate()
        out = out.decode("utf-8")
        err = err.decode("utf-8")
        if process.returncode == 84 and err:
            print(Fore.GREEN + "Test passed" + Style.RESET_ALL)
        else:
            print(Fore.RED + "Test failed" + Style.RESET_ALL)
            exit(1)
    except Exception as e:
        print(Fore.RED + "Test failed due to error: " + str(e) + Style.RESET_ALL)
    print("")
