import os


def generate_file(name: str, size: int) -> None:
    with open(name, 'wb') as f:
        f.write(os.urandom(size));
    
    print(f"Binary file '{name}' of size {size} bytes created successfully.")


def main():
    files_dir = "files"
    os.makedirs(files_dir, exist_ok=True)

    for i in range(10, 20):
        generate_file("files/" + str(i) + ".bin", 3 ** i)


if __name__ == '__main__':
    main()

