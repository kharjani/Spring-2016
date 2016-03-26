## CS 104: Spring 2016 Homework 4 Tests

Here you will find two folders containing the tests that are being run with HW4. We are releasing these tests earlier than normal so you can fix errors and test your code. 

Before raising a grading dispute, please copy these test files into your VM and run them against your program. In the event you would like to raise a grading dispute, create a new issue on GitHub by responding to the grade report you were issued. Assigning your grader to the issue and leave a comment explaining what you want regraded and what you believe the error is. 

### Running the Tests
There is a `Python` script included in this directory which can be used to automatically run all of the tests. First you will have to make some changes to your `Facile.cpp` program. Specifically, your `main()` function should look like this:

```cpp
int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        std::cerr << "Program usage: ./Facile inputFile outputFile" << std::endl;
        return 1;
    }

    std::ifstream inFile(argv[1]);
    std::ofstream outFile(argv[2]);
    if (!inFile)
    {
        std::cerr << "Could not open file " << argv[1] << std::endl;
        return 1;
    }
    if(!outFile)
    {
        std::cerr << "Could not open file " << argv[2] << std::endl;
        return 1;
    }

    interpretProgram(inFile, outFile);
    inFile.close();
    outFile.close();

    return 0;
}
```

This change will automatically write your answers out to the file passed by command line arguments.

Next you will have to compile your program into an executable, and make sure the executable is placed within this directory!

Finally line [4](https://github.com/usc-csci104-spring2016/homework-resources/blob/master/hw4_tests/run_tests.py#L4) should be changed to the name of your executable -- case sensitive. Just change the name inside the single quotes.

Once this is set up, you can run the script with the command: `python run_tests.py` at the command line. The output files will be placed in the `test_output/` folder. To check your answers, open the files and compare them against the solution output. 
