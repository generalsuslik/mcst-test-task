import os


def generate_file(name: str, size: int) -> None:
    with open(name, 'wb') as f:
        f.write(os.urandom(size));
    
    print(f"Binary file '{name}' of size {size} bytes created successfully.")


def generate_files(n: int) -> None:
    files_dir = "files"
    os.makedirs(files_dir, exist_ok=True)

    start_pow = 8
    for i in range(start_pow, n + start_pow):
        generate_file("files/" + str(i - start_pow + 1) + ".bin", 2 ** i - 20)

