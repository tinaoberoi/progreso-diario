# Regression Testing

* type of software testing to confirm that a recent program or code change has not adversely affected existing features.
Regression Testing can be carried out using the following techniques:
- Retest All (all the tests in the existing test bucket or suite should be re-executed)
- Regression Test Selection (Instead of re-executing the entire test suite, it is better to select part of the test suite to be run)
- Prioritization of Test Cases(Prioritize the test cases depending on business impact, critical & frequently used functionalities. Selection of test cases based on priority will greatly reduce the regression test suite.)

### Difference between Re-Testing and Regression Testing:
Retesting means testing the functionality or bug again to ensure the code is fixed. If it is not fixed, Defect needs to be re-opened. If fixed, Defect is closed.
Regression testing means testing your software application when it undergoes a code change to ensure that the new code has not affected other parts of the software.

### Challenges:
- With successive regression runs, test suites become fairly large.  Due to time and budget constraints, the entire regression test suite cannot be executed
- Minimizing the test suite while achieving maximum Test coverage remains a challenge
- Determination of frequency of Regression Tests, i.e., after every modification or every build update or after a bunch of bug fixes, is a challenge.

An effective regression strategy, save organizations both time and money. As per one of the case study in banking domain, regression saves up to 60% time in bug fixes(which would have been caught by regression tests) and 40%  in money 
