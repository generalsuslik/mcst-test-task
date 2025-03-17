import subprocess

from generator import generate_files


def compile_main():
    subprocess.run(["make"], check=True)


def compile_etalone():
    etalone = "etalone.cpp"
    process = "src/process.cpp"
    binary  = "bin/etalone"
    subprocess.run(["clang++", "-Iinc", etalone, process, "-o", binary], check=True)

def main() -> None:
    n = 10
    print(f"Generating {n} files:")
    generate_files(n)

    compile_main()
    compile_etalone()

    for i in range(n):
        file_path = f"files/{10 + i}.bin"
        output_main    = subprocess.run(["./bin/main", file_path], capture_output=True, text=True)
        output_etalone = subprocess.run(["./bin/etalone", file_path], capture_output=True, text=True)

        if output_main.stdout == output_etalone.stdout:
            print(f"[{i + 1}] ✅ Outputs are equal")
        else:
            print(f"[{i + 1}] ❌ Outputs are different")
            print("main output:\n", output_main.stdout)
            print("etalone output:\n", output_etalone.stdout)


if __name__ == '__main__':
    main()

