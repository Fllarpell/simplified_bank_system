**Introduction:**

    It's banking system simulation using various design patterns. 
    This problem is focused on creating a non-interactive system that processes a series of banking operations.

**Input**

The input file is structured as follows:

    The first line contains a single integer n -- denoting the number of banking operations.
    Each of the next n lines contains a banking operation command. The format for each command is [T]N, where T is the type of operation and N
    is the detail of the operation. Each parameter in the operation is denoted as [type]parameterName. 
    Accounts' names consist of lowercase and uppercase latin letters only.

        - "Create Account $[string]accountType $[string]accountName $[float]initialDeposit" (accountType can be Savings, Checking, or Business).
        - "Deposit $[string]accountName $[float]depositAmount".
        - "Withdraw $[string]accountName $[float]withdrawalAmount".
        - "Transfer $[string]fromAccountName $[string]toAccountName $[float]transferAmount".
        - "View $[string]accountName" (show details about a certain account).
        - "Deactivate $[string]accountName" (deactivate a certain account).
        - "Activate $[string]accountName" (activate a certain account).

**Output**

The output file is structured as follows:

    The ordered list of outputs matches the events in the input. 
    Each event output is on its own line. Note that $transactionFeePercentage, 
    the output should have only one digit after the decimal point, e.g. "1.5%". 
    As for other float values like depositAmount, exactly two digits should be shown after the decimal point.

        1. "A new $[string]accountType account created for $[string]accountName with an initial balance of $[float]initialDeposit."
        2. "$[string]accountName successfully deposited $[float]depositAmount. New Balance: $[float]balance."
        3. "$[string]accountName successfully withdrew $[float]withdrawalAmount. New Balance: $[float]balance. Transaction Fee: $[float]transactionFee ($[float]transactionFeePercentage%) in the system."
        4. "$[string]fromAccountName successfully transferred $[float]transferAmount to $[string]toAccountName. New Balance: $[float]balance. Transaction Fee: $[float]transactionFee ($[float]transactionFeePercentage%) in the system."
        5. "$[string]accountName's Account: Type: $[string]accountType, Balance: $[float], State: $[string]state, Transactions: $[TransactionEventList]history." ($state can either be Active or Inactive. The history of the transactions is saved without the fees. The history is shown by the order in which the transaction were carried out. An element in the history list can be one of the following: a) "Initial Deposit $[float]initialDeposit". b) "Deposit $[float]depositAmount". c) "Withdrawal $[float]withdrawalAmount". d) "Transfer $[float]transferAmount")
        6. "$[string]accountName's account is now deactivated."
        7. "$[string]accountName's account is now activated."


**Examples of input and output:**

    Input:
        5
        Create Account Savings JohnDoe 450.0
        Withdraw JohnDoe 150.0
        Create Account Checking JaneDoe 300.0
        Transfer JohnDoe JaneDoe 500.0
        View JohnDoe

    Output:
        A new Savings account created for JohnDoe with an initial balance of $450.00.
        JohnDoe successfully withdrew $147.75. New Balance: $300.00. Transaction Fee: $2.25 (1.5%) in the system.
        A new Checking account created for JaneDoe with an initial balance of $300.00.
        Error: Insufficient funds for JohnDoe.
        JohnDoe's Account: Type: Savings, Balance: $300.00, State: Active, Transactions: [Initial Deposit $450.00, Withdrawal $150.00].
    

    Input:
        7
        Create Account Savings JohnDoe 70.0
        Create Account Checking JaneDoe 80.0
        Deposit JohnDoe 30.0
        Transfer JohnDoe Alice 1200.0
        Create Account Savings Alice 50.0
        Deactivate JohnDoe
        Transfer JohnDoe Alice 1200.0

    Output:
        A new Savings account created for JohnDoe with an initial balance of $70.00.
        A new Checking account created for JaneDoe with an initial balance of $80.00.
        JohnDoe successfully deposited $30.00. New Balance: $100.00.
        Error: Account Alice does not exist.
        A new Savings account created for Alice with an initial balance of $50.00.
        JohnDoe's account is now deactivated.
        Error: Account JohnDoe is inactive.


    Input:
        8
        Create Account Savings JohnDoe 70.0
        Create Account Checking JaneDoe 80.0
        Deactivate JohnDoe
        Transfer JohnDoe Alice 20.0
        Activate JohnDoe
        Transfer JohnDoe Alice 1200.0
        Create Account Savings Alice 50.0
        Transfer JohnDoe Alice 1200.0

    Output:
        A new Savings account created for JohnDoe with an initial balance of $70.00.
        A new Checking account created for JaneDoe with an initial balance of $80.00.
        JohnDoe's account is now deactivated.
        Error: Account Alice does not exist.
        JohnDoe's account is now activated.
        Error: Account Alice does not exist.
        A new Savings account created for Alice with an initial balance of $50.00.
        Error: Insufficient funds for JohnDoe.



