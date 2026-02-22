#!/usr/bin/env python3
"""
Cross-platform test runner for the DataStructures program.
Works on both Windows and Linux.
Reads test cases from tests.json
"""

import subprocess
import platform
import json
import os
import sys

def get_executable():
    """Get the correct executable path based on the platform."""
    script_dir = os.path.dirname(os.path.abspath(__file__))

    if platform.system() == "Windows":
        return os.path.join(script_dir, "main.exe")
    else:
        return os.path.join(script_dir, "main")

def load_tests(filepath="Tests/tests.json"):
    """Load test cases from JSON file."""
    script_dir = os.path.dirname(os.path.abspath(__file__))
    json_path = os.path.join(script_dir, filepath)

    with open(json_path, "r") as f:
        return json.load(f)

def run_test(datastructure_id, datatype, commands, expected, test_name):
    """
    Run the program with given input and check for expected outputs.

    Returns:
        (passed, output) tuple
    """
    executable = get_executable()

    if not os.path.exists(executable):
        print(f"ERROR: Executable '{executable}' not found!")
        print("Please compile your program first.")
        return False, ""

    # Build input: select datastructure, select datatype, then commands
    input_lines = [str(datastructure_id), str(datatype)] + commands
    input_text = "\n".join(input_lines) + "\n"

    try:
        result = subprocess.run(
            [executable],
            input=input_text,
            capture_output=True,
            text=True,
            timeout=10,
            cwd=os.path.dirname(executable)
        )

        output = result.stdout + result.stderr

        # Check for expected outputs
        all_found = True
        missing = []
        for exp in expected:
            if exp not in output:
                missing.append(exp)
                all_found = False

        if all_found:
            print(f"  [PASS] {test_name}")
            return True, output
        else:
            print(f"  [FAIL] {test_name}")
            for m in missing:
                print(f"         Missing: '{m}'")
            return False, output

    except subprocess.TimeoutExpired:
        print(f"  [FAIL] {test_name} - Timeout!")
        return False, ""
    except Exception as e:
        print(f"  [FAIL] {test_name} - Error: {e}")
        return False, ""

def main():
    print("=" * 60)
    print("DataStructures Test Suite")
    print(f"Platform: {platform.system()}")
    print("=" * 60)

    # Load tests from JSON
    try:
        test_data = load_tests()
    except FileNotFoundError:
        print("ERROR: tests.json not found!")
        return 1
    except json.JSONDecodeError as e:
        print(f"ERROR: Invalid JSON in tests.json: {e}")
        return 1

    total_passed = 0
    total_failed = 0

    # Run tests for each data structure
    for ds_name, ds_data in test_data.items():
        ds_id = ds_data["id"]
        tests = ds_data["tests"]

        if not tests:
            continue

        print(f"\n{ds_name.upper().replace('_', ' ')}")
        print("-" * 40)

        for test in tests:
            passed, _ = run_test(
                datastructure_id=ds_id,
                datatype=test["datatype"],
                commands=test["commands"],
                expected=test["expected"],
                test_name=test["name"]
            )

            if passed:
                total_passed += 1
            else:
                total_failed += 1

    print("\n" + "=" * 60)
    print(f"Results: {total_passed} passed, {total_failed} failed")
    print("=" * 60)

    return 0 if total_failed == 0 else 1

if __name__ == "__main__":
    sys.exit(main())
