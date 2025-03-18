import subprocess

from generator import generate_files


def compile():
    subprocess.run(["make"], check=True)


def main() -> None:
    n = 10
    print(f"Generating {n} files:")
    generate_files(n)

    compile()

    for i in range(n):
        file_path = f"files/{i + 1}.bin"
        output_main    = subprocess.run(["./bin/main", file_path], capture_output=True, text=True)
        output_etalone = subprocess.run(["./bin/etalone", file_path], capture_output=True, text=True)

        if output_main.stdout == output_etalone.stdout:
            print(f"[{i + 1}] ✅ Outputs are equal: {output_main.stdout.strip()} = {output_etalone.stdout.strip()}")
        else:
            print(f"[{i + 1}] ❌ Outputs are different")
            print("main output:\n", output_main.stdout.strip())
            print("etalone output:\n", output_etalone.stdout.strip())


if __name__ == '__main__':
    main()

