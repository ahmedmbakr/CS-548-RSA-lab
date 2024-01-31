# RSA Lab by Ahmed Bakr

## How to Run

The compilation of this code utilizes the `MakeFile`. To run, open the terminal in this directory as the root directory and type `make`.

After the command finishes the target binary outputs will exist in `outputs` folder. There will exist one binary file for each task. For example, the output binrary file for the first task is `outputs/task1`, and so on.

## Task 1 (Deriving the private key)

The code for this task can be found inside `task1.c` file.
The code is self explanatory and is full with comments to describe every step done.
However, I will emphasize on the verification of `d`, where it can be verified by confirming that `d * e mod phi_n == 1`, as shown in the output from running the program below.
It is also worth mentioning that to run this task, open the terminal and write `make run_task1`.

![Alt text](images/task1-output.png)

## Task 2 (Encrypting a Message)

The code for this task can be found inside `task2.c` file.
The hex value of the message: `AhmedBakr-12290214` is converted via the website as shown in the attached image below.

![Alt text](images/name-to-hex.png)

The output hex value is the encoded message, as shown in line 31 in the code.
It is also worth mentioning that to run this task, open the terminal and write `make run_task2`.
The output after executing the program is:

![Alt text](images/task2-output.png)

## Task 3 (Decrypting a Message)

The code for this task can be found inside `task3.c` file.
The hex value of the ciphertext (encrypted message) is given as an input from the previous task.
The output of the program is shown in the following screenshot.

![Alt text](images/task3-output.png)

The output of decryption message (the output hex) is translated back to ascii as shown in the following image that proves that we were able to retrieve the original message from task 2.

![Alt text](images/hex-to-name.png)
