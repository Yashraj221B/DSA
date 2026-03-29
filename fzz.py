import random
import subprocess
import time

def correct(path):
    paths = path.split("/")
    newPaths = []
    for i in paths:
        if i == "" or i == '.':
            continue
        elif i == '..':
            if newPaths:
                newPaths.pop()
        else:
            newPaths.append(i)
    return "/" + "/".join(newPaths)


def cpp_output(path):
    result = subprocess.run(
        ["./simplify"],
        input=path,
        text=True,
        capture_output=True
    )
    return result.stdout.strip()


def generate_path():
    tokens = ["", ".", "..", "a", "b", "c", "abc", "...", "..b", "b.."]
    length = random.randint(1, 20)

    path = ""
    for _ in range(length):
        path += "/" + random.choice(tokens)

    if random.random() < 0.5:
        path += "/"

    return path

def test(iterations=100000):
    start = time.time()

    for i in range(iterations):
        path = generate_path()
        out1 = correct(path)
        out2 = cpp_output(path)

        if out1 != out2:
            print("FOUND FAILURE")
            print("Input   :", path)
            print("Python  :", out1)
            print("C++     :", out2)
            return

        if i % 100 == 0 and i != 0:
            elapsed = time.time() - start
            speed = i / elapsed if elapsed > 0 else 0
            print(f"Checked: {i} | Speed: {int(speed)} checks/sec | {path}")

    print("No failures found")


test()
