## Current Workflow Status

![example workflow](https://github.com/uofu-emb/2024_lab2_Chase_Eddie_Sameeran/actions/workflows/main.yml/badge.svg)

# Lab 2 Testing (Eddie, Sameeran, Chase)
# DoomBot5000 Branch

# Learning objectives:
Organize a project.
Read and document unfamiliar code.
Navigate documentation.
Write unit tests.
Run tests in simulation
Run tests on hardware
Write a manual test procedure.
Refactor for ease of testing.

# Test Pass/Fail Status
![Application Screenshot](https://github.com/uofu-emb/2024_lab2_Chase_Eddie_Sameeran/blob/eddieDoomBot5000/tests_passing2.png)

# Activity 1
Clone the Unity repo as a submodule. git submodule add https://github.com/ThrowTheSwitch/Unity.git lib/unity
Update the submodule contents (a common problem with submodules, the submodule folder may be empty) git submodule update --init --recursive


# Activity 2
Several tasks are defined in the .vscode configuration in the class template. The launch.json and task.json files have been modified to use the currently selected CMake target binary rather than the single target allowed by the Pico extension. You can switch the current launch/build target from the Command Palette or the CMake extension side panel with "Set Launch/Debug Target".

Read throught the test.c example into test directory.
Verify that all tests pass. To run the test, you have a two options.
you can set the CMake Launch/Debug target and flash using the "Flash" task accessible in the Command Palette.
You can use picotool directly to flash the test ELF.

Tests PASSED

# Activity 3
Discuss with your partner how to approach this particular code. Come up with a brief plan.

You may find a particular pattern or strategy works well for you. Discuss with your partner if their preferred strategy is the same or different from yours.
- Change variables descritption 
- Change timing 
- Comenting functions to see the behavior

Discuss with your partner what type of code might cause your proposed strategies to break down.

# Activity 4
As you do your exploration of the code, add comments to the file explaining what it does, how it works, how it is organized, etc.

You do not have to understand perfectly what is going on to proceed. Once you have a rough idea and added comments, commit the changes to the files.

# Activity 5
If you have not already done so, flash the code to your microcontroller and observe the behavior of the system.

Delete the calls to vTaskStartScheduler (make sure you have committed prior to this!). Predict what you think will happen.
-it wont schedule the task_handle
Compile your changes and flash the micontroller. Does the behavior match your prediction?
-the blink_task is not working 
Restore your previous code. You can use the command git checkout src/main.c to restore the file to the current committed version of the file.

# Activity 6
Write down a test plan in a file, for example tests/manual/something.md
Commit it to source control.
Work with another group. Follow their test plan.
Discuss with them your experience. Was there anything unclear or missing? Does the plan describe the behavior of the system correctly? Are there any edge cases the test plan would miss? How long does it take to go through the test plan?

# Activity 7
Find the execution contexts: the main function, interrupt handlers, and thread entry points.
Identify the behavioral code in these contexts. We will refactor this code in following activity.
Find any infinite loops in the code.
Identify the difference between setup and repeated execution.
Identify any time dependent behavior, especially delays between iterations.

# Activity 8
Make sure all code is committed before you make any changes.
We need to make sure we know what the code was before our changes.
Use git diff or git difftool to compare with the previous state.
If things go wrong, you can always revert back to the working state. (Use git checkout -- file.c)
Create a new header file in the include directory to hold the definition of your function.
Create a new C code file in the src directory to hold the implementation of your code.
Add this file to the list of files in the add_executable statements in your CMakeLists.txt files.
Take a block of code you identified in the infinite loop of your main execution context. Create a function in your new files, and move all of the code in a block into it.
Put a call to the function where the code used to be.
Compile the code. You will be missing includes, variables, references, outputs, etc. We will deal with this in the next activity.
You can use the compiler as a guide for refactoring.
Some IDEs even provide automatic refactoring.

# Activity 9
For each missing variable or reference in the function you created, add an input to the function.
If you need to return more than one value, pass it as an out param, which is a pointer to a value in the caller that the function will populate.
Once your function is compiling, switch to the original location it was called from and populate the parameters of the function.

# Activity 10
In the function you extracted, identify any references to global variables, HAL devices, system functions, etc.
See if you can remove the dependency by separating the concern of your code from the behavior of the dependency. For example, you could move a call to get data from a peripheral to the caller and pass the data into your function instead.
Create new inputs to your function for pointers to dependencies.

# Activity 11 (Not Applicable - No one in the class got RENODE to work)
Make sure your code compiles and everything is committed.
Running code in the Renode simulator, so we can run our tests in GitHub actions.
