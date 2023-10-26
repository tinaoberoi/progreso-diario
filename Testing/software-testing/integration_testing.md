Although each software module is unit tested, defects still exist for various reasons like

- A Module, in general, is designed by an individual software developer whose understanding and programming logic may differ from other programmers. Integration Testing becomes necessary to verify the software modules work in unity
- At the time of module development, there are wide chances of change in requirements by the clients. These new requirements may not be unit tested and hence system integration Testing becomes necessary.
- Interfaces of the software modules with the database could be erroneous
- External Hardware interfaces, if any, could be erroneous
- Inadequate exception handling could cause issues.

Integration Test Case differs from other test cases in the sense it focuses mainly on the interfaces & flow of data/information between the modules. Here priority is to be given for the integrating links rather than the unit functions which are already tested.

How to do Integration Testing?
The Integration test procedure irrespective of the Software testing strategies (discussed above):

Prepare the Integration Tests Plan
Design the Test Scenarios, Cases, and Scripts.
Executing the test Cases followed by reporting the defects.
Tracking & re-testing the defects.
Steps 3 and 4 are repeated until the completion of Integration is successful.
Brief Description of Integration Test Plans:
It includes the following attributes:

Methods/Approaches to testing (as discussed above).
Scopes and Out of Scopes Items of Integration Testing.
Roles and Responsibilities.
Pre-requisites for Integration testing.
Testing environment.
Risk and Mitigation Plans.
Entry and Exit Criteria of Integration Testing
Entry and Exit Criteria to Integration testing phase in any software development model

Entry Criteria:

Unit Tested Components/Modules
All High prioritized bugs fixed and closed
All Modules to be code completed and integrated successfully.
Integration tests Plan, test case, scenarios to be signed off and documented.
Required Test Environment to be set up for Integration testing
Exit Criteria:

Successful Testing of Integrated Application.
Executed Test Cases are documented
All High prioritized bugs fixed and closed
Technical documents to be submitted followed by release Notes.