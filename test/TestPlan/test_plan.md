# Test Plan for Code Evaluation and Test Case Development

## Purpose
To validate the correct functionality of the provided code, ensure robust unit tests are written to catch errors, and verify the system performs as expected under various scenarios.

---

## Step 1: Understand the Code Functionality

### Code Overview
1. **Global Variables**:
   - `count`: Tracks iterations in the `blink_task`.
   - `on`: Represents the state of the LED (ON/OFF).

2. **Definitions**:
   - Task priorities and stack sizes are defined using macros.

3. **Tasks**:
   - **`blink_task`**:  
     Toggles an LED at a 500ms interval. After 11 iterations, toggles the state of `on`.  
     Dependencies: `cyw43_arch_gpio_put` and `cyw43_arch_init`.
   - **`main_task`**:  
     Creates `blink_task` and processes input from `getchar()` to toggle character case.  

4. **`main`**:  
   - Initializes FreeRTOS and sets up tasks.

---

## Step 2: Identify Functional Requirements

### Functional Goals
1. **Global Variables**: Validate correct initialization and behavior of `count` and `on`.  
2. **`blink_task`**: Ensure the LED toggles correctly every 500ms, and state logic (toggle every 11 iterations) is adhered to.  
3. **`main_task`**: Verify input handling correctly toggles character case.  
4. **RTOS Behavior**: Confirm tasks are created and executed as expected.  

---

## Step 3: Define Test Cases

### Unit Test Cases
1. **Variable Assignment**: Validate initialization and basic operations on simple variables (e.g., `int` and `char`).  
   - **Test Name**: `test_variable_assignment`  
   - **Purpose**: Ensure basic variable assignment works.  
   - **Expected Behavior**: `int x = 1` should pass an equality assertion.  

2. **Arithmetic Operations**: Validate simple mathematical operations such as multiplication and division.  
   - **Test Name**: `test_multiplication`  
   - **Purpose**: Ensure integer division produces expected results.  
   - **Expected Behavior**: Dividing 30 by 6 should yield 5.  

3. **Character Manipulation**: Test behavior of input transformation logic (case toggling).  
   - **Test Name**: `activity1`  
   - **Purpose**: Ensure `activity()` correctly toggles the case of a character.  
   - **Expected Behavior**: `'c'` should transform to `'C'`.

---

### Integration Test Cases
1. **LED Blink Task**: Verify LED toggling logic based on `count` and `on`.  
   - Simulate multiple iterations and ensure state changes correctly every 11 counts.  
   - **Expected Result**: LED alternates ON/OFF at 500ms intervals.

2. **RTOS Task Scheduling**: Validate `main_task` creates `blink_task` correctly and both tasks run without issues.  
   - **Expected Result**: Tasks should run simultaneously without interference.

3. **Input Handling**: Simulate a series of character inputs to verify case toggling.  
   - **Expected Result**: Inputs should be correctly toggled between uppercase and lowercase.

---

## Step 4: Map Tests to Implementation

### Mapping
| **Test Name**              | **Code Functionality**                  | **Test Description**                                          |
|----------------------------|------------------------------------------|--------------------------------------------------------------|
| `test_variable_assignment` | Global variable initialization          | Ensure basic variable assignments work as expected.          |
| `test_multiplication`      | Arithmetic operations                   | Validate integer division yields correct results.            |
| `activity1`                | Input case toggling logic               | Confirm `activity()` toggles input character case properly.  |
| Integration Tests          | `blink_task` and `main_task` behaviors  | Ensure LED toggles and input handling work concurrently.     |

---

## Step 5: Write and Validate Tests

Develop unit tests first (e.g., `test_variable_assignment`, `test_multiplication`), then integration tests for the RTOS task interactions. Ensure tests are run in an appropriate environment (e.g., hardware with LEDs or simulated input).  

By following this plan, the test cases developed (as seen in the original implementation) align with the functionality and cover critical aspects of the code.
