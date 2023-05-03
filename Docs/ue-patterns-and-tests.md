# Unreal Engine Design Patterns and Testing Strategy

Person:

- Imagine you are game architecture specialist. Can you tell me the design patterns commonly seen in the Unreal Engine-based FPS games? Please note that, I'm referring to technical design patterns (not about character design, gameplay design, etc.). Here is an example:

```text
event-driven pattern

unreal engine-based game uses blueprint to emit events and implement c++ handler functions to handle these events

this pattern gives the game developers flexibility as they can drag and drop events in the blueprint graph, and also guarantee optimal performance because all the heavy-lifting is done by the high performance c++ code.
```

ChatGPT:

- As a game architecture specialist, I can certainly provide you with an overview of some common technical design patterns seen in Unreal Engine-based FPS games. These design patterns are utilized to create a maintainable, flexible, and efficient codebase:

1. Component-based pattern
Unreal Engine uses an Actor-Component architecture, where Actors are made up of reusable Components. This pattern allows for flexibility in creating game objects and encourages code reuse. Components can be written in C++ and attached to Actors in the editor or programmatically.
2. Singleton pattern
This pattern is used to ensure that a class has only one instance and provides a global point of access to it. Unreal Engine has built-in support for singletons through its GameplayStatics class and GameInstance class. These classes are used to store and manage global game data, as well as provide centralized access to various game systems.
3. Observer pattern
The observer pattern allows objects to 'subscribe' to events and be notified when these events occur. Unreal Engine supports this pattern through its Delegate system. Delegates are used to define and bind event callbacks, allowing objects to communicate with each other without being tightly coupled.
4. State pattern
This pattern is commonly used to represent the state of an object, such as a character or weapon, and manage the object's behavior based on its state. In Unreal Engine, this can be achieved using Enums and Switch nodes in Blueprints, or through C++ classes and state machines.
5. Factory pattern
The factory pattern is used to create objects without specifying the exact class of the object that will be created. This pattern is useful for creating a flexible and extensible system for spawning game objects. In Unreal Engine, you can use the SpawnActor function with a UClass parameter to create instances of different classes at runtime.
6. Prototype pattern
This pattern involves creating new objects by copying existing objects (prototypes) and modifying their properties as needed. In Unreal Engine, this can be achieved using the DuplicateObject function in C++ or the Duplicate node in Blueprints. This pattern is particularly useful for creating variations of game objects, such as different weapon types or enemy classes.
7. Data-driven pattern
This pattern involves storing game data (such as level layouts, item stats, or character abilities) in external files or databases, allowing for easy modification and extension. Unreal Engine supports this pattern through its use of Data Assets, DataTables, and other asset types that can be edited in the editor or loaded from external sources at runtime.

Person:

- This is a good start. I want to know if there are design pattern regarding the interaction between blueprint and c++?

ChatGPT:

- Certainly! There are several design patterns that deal with the interaction between Blueprints and C++ in Unreal Engine. These patterns aim to create a balance between the flexibility offered by Blueprints and the performance and maintainability of C++ code:

1. Blueprint Function Library
A Blueprint Function Library is a C++ class that contains a collection of static functions that can be called from Blueprints. This pattern allows you to write reusable and modular C++ code that can be exposed to Blueprints, offering both performance and ease of use.
2. Native Event pattern
Native Events are functions declared in a C++ class with a special UFUNCTION macro and can be overridden in Blueprints. The pattern involves creating a base implementation in C++ and allowing Blueprint developers to extend or modify the functionality in Blueprints. This pattern provides flexibility while maintaining the core logic in C++.
3. Blueprint Implementable Interface
A Blueprint Implementable Interface is a C++ interface that can be implemented by both C++ and Blueprint classes. This pattern allows you to define a common interface for different classes, enabling communication and interaction between C++ and Blueprint objects without tight coupling.
4. Blueprint Callable Function pattern
Blueprint Callable Functions are C++ member functions declared with the UFUNCTION macro and the BlueprintCallable specifier. These functions can be called directly from Blueprints, allowing you to expose specific functionality from your C++ code to Blueprint developers, while still maintaining the performance benefits of C++.
5. Property Binding pattern
This pattern involves using UPROPERTY macros to expose variables in a C++ class to Blueprints, allowing Blueprint developers to modify these variables and bind them to UI elements or other game systems. By using the BlueprintReadOnly or BlueprintReadWrite specifiers, you can control the level of access Blueprints have to the variables.
6. Event Dispatchers pattern
Event Dispatchers are a way to create custom events in Blueprints that can be triggered from C++ code. This pattern involves declaring Event Dispatchers in your C++ class and calling them when specific conditions are met, allowing Blueprint developers to bind their own functionality to these events without modifying the C++ code directly.

By using these design patterns, you can create a robust and flexible game architecture that leverages the strengths of both Blueprints and C++ in Unreal Engine.

Person:

- Great. Now, I want to know some debugging patterns to help me troubleshoot crashes, bugs, or edge cases.

ChatGPT:

- Debugging patterns and techniques are essential for identifying and resolving issues in your game. Here are some common debugging patterns and practices that can help you troubleshoot crashes, bugs, or edge cases in Unreal Engine-based games:

1. Logging and Console Commands
Use UE_LOG macros in your C++ code to output messages to the console and log files, providing useful information about the current state of your game. Additionally, you can create custom console commands using the UConsoleCommand macro to execute debugging functions during runtime.
2. Breakpoints and Debugging in Visual Studio or Xcode
Set breakpoints in your C++ code to pause the execution of your game and inspect the current state of variables, objects, and call stacks. You can use Visual Studio, Xcode, or other supported IDEs to debug your Unreal Engine project and step through the code as needed.
3. Blueprint Debugging
Unreal Engine provides built-in support for Blueprint debugging, including breakpoints, stepping through nodes, and watching variables. Use these features to debug logic implemented in Blueprints and identify any issues in the visual scripting system.
4. Debug Drawing
Use debug drawing functions (such as DrawDebugLine, DrawDebugBox, and DrawDebugSphere) in your C++ code or the corresponding nodes in Blueprints to visualize important information directly in the game world, such as collision volumes, line traces, or AI navigation paths.
5. Profiling Tools
Unreal Engine comes with various profiling tools (e.g., the Session Frontend, Stat commands, and the GPU Visualizer) that can help you identify performance issues and optimize your game. Use these tools to gather data about your game's performance and pinpoint areas that need optimization.
6. Unit Testing and Automation
Create unit tests for your C++ code using Unreal Engine's automation framework (FAutomationTestBase) to ensure the stability and correctness of your codebase. Additionally, you can create custom automation tests in Blueprints using the Functional Testing Framework to test specific functionality or scenarios in your game.
7. Assertions and Error Handling
Use check, checkSlow, and ensure macros in your C++ code to add assertions that validate assumptions and catch potential issues during development. Implement proper error handling in your code and use try-catch blocks to gracefully handle exceptions and avoid crashes.
8. Version Control and Bug Tracking
Utilize version control systems (such as Git or Perforce) to track changes in your codebase and easily revert to previous working versions if needed. Use bug tracking software (e.g., Jira or Trello) to document, prioritize, and assign tasks related to fixing issues and crashes.

By employing these debugging patterns and practices, you can effectively troubleshoot issues in your Unreal Engine-based game and ensure a stable and polished final product.

Person:

- I want to know how to quickly understand a complex game project that consists of many blueprint graphs and c++ classes. I want to know how they interact with each other, what data they pass, and what events they generate.

ChatGPT:

- Understanding a complex game project with many Blueprint graphs and C++ classes can be challenging. However, there are several strategies and tools you can use to familiarize yourself with the project and get a better grasp of the interactions, data flow, and events:

1. Documentation and Code Comments
Start by reviewing any available documentation or code comments that explain the overall architecture, design patterns, and key components of the project. This will give you a high-level understanding of the project's structure and functionality.
2. Project Structure and Naming Conventions
Examine the project's folder structure and naming conventions to identify the organization of assets, Blueprints, and C++ classes. This will help you navigate the project more efficiently and understand how different components relate to each other.
3. Class Hierarchy and Relationships
Use Unreal Engine's Class Viewer to explore the class hierarchy and relationships between C++ classes and Blueprint classes. This will give you an overview of the project's inheritance structure and help you identify key base classes and their derived classes.
4. Call Graphs and Function Calls
Use Visual Studio, Xcode, or other supported IDEs to generate call graphs and analyze function calls between C++ classes. This will help you understand the flow of execution and the interactions between different parts of the codebase.
5. Blueprint Event Graphs and Function Graphs
Examine the Blueprint Event Graphs and Function Graphs to understand the flow of logic in the visual scripting system. Pay special attention to the nodes that interact with C++ classes, such as calling C++ functions, modifying C++ properties, or binding to C++ events.
6. Data Flow and Variables
Identify key variables and data structures used in the project, both in C++ and Blueprints. Analyze how data is passed between functions, classes, and Blueprint nodes. This will help you understand the flow of data and the dependencies between different components.
7. Event Dispatchers and Delegate Bindings
Review the use of Event Dispatchers and Delegate bindings in both C++ and Blueprints. This will help you understand the custom events and callbacks used in the project and how they interact with each other.
8. Debugging and Breakpoints
Set breakpoints in C++ code and Blueprint nodes to pause the execution of the game and inspect the current state of variables, objects, and call stacks. Stepping through the code in a debugger will help you gain a deeper understanding of the interactions and data flow within the project.
9. Communication Patterns
Identify the communication patterns used in the project, such as Blueprint Interfaces, Event Dispatchers, or direct function calls. Understanding these patterns will help you comprehend how different components communicate and interact with each other.
10. Collaboration and Knowledge Sharing
If possible, collaborate with the project's developers or other team members to gain insights into the project's design, architecture, and implementation details. They can help you understand complex interactions and provide valuable context about the project's history and evolution.

By following these strategies and utilizing the available tools, you can quickly gain a better understanding of a complex game project with many Blueprint graphs and C++ classes, and learn how they interact with each other, pass data, and generate events.

Person:

- Is there any software that can generate high-level design diagram from an Unreal game project?

ChatGPT:

- As of my knowledge cutoff in September 2021, there isn't a dedicated software that automatically generates high-level design diagrams specifically for Unreal Engine game projects. However, there are some tools and techniques you can use to create or visualize parts of your project:

1. Unreal Engine's Class Viewer and Reference Viewer
These built-in tools allow you to explore the class hierarchy and relationships between C++ classes, Blueprint classes, and assets. While they don't generate a design diagram per se, they can help you understand the structure of your project and identify key components.
2. IDE's built-in tools (e.g., Visual Studio, Xcode)
Some integrated development environments (IDEs) offer features to visualize the class hierarchy, call graphs, or dependency graphs for your C++ code. These tools can give you an overview of the structure and relationships within your C++ classes. Keep in mind that these tools will only cover the C++ part of your project and not the Blueprint side.
3. UML Diagrams
You can create Unified Modeling Language (UML) diagrams to represent the high-level structure and relationships of your game project. While there's no automatic tool specifically for Unreal Engine projects, you can use general-purpose UML tools like draw.io, Visual Paradigm, or StarUML to create these diagrams manually. This process will require you to analyze your project's components and translate them into UML representations.
4. Custom Scripts
You could potentially write custom scripts to parse your project's source code, assets, and configuration files to generate a high-level design diagram. This approach would likely involve considerable effort and require a good understanding of Unreal Engine's internal structure and file formats.

Overall, while there isn't a dedicated software to automatically generate high-level design diagrams for Unreal Engine game projects, you can use a combination of the built-in tools, IDE features, manual diagramming, and custom scripts to create a representation of your project's structure and relationships.

Person:

- OK that's fine. Is it possible to automatically generate high-level diagram from a single blueprint graph?

ChatGPT:

- As of my knowledge cutoff in September 2021, Unreal Engine does not provide a built-in feature to automatically generate a high-level diagram from a single Blueprint graph. However, there are a few alternative ways you could consider to represent the structure and flow of a Blueprint graph:

1. Screenshots and Annotations
You can take screenshots of your Blueprint graph and use image editing software to add annotations, highlights, or callouts to emphasize key areas and interactions within the graph. This method requires manual effort but allows you to create a custom representation tailored to your specific needs.
2. Exporting and Importing Blueprints as Images
Unreal Engine allows you to export a Blueprint graph as an image file (PNG, JPEG, etc.) by right-clicking on the graph background and selecting "Export as Image." You can then import this image into a diagramming tool or image editor to create a high-level representation of the graph, adding annotations, labels, or grouping related nodes as necessary.
3. Custom Tools or Scripts
You could potentially create a custom tool or script to parse the Blueprint graph's data and generate a high-level diagram. This approach would require a good understanding of Unreal Engine's Blueprint data formats and a way to extract the necessary information to create a meaningful representation of the graph structure.

Although Unreal Engine does not have a built-in feature for generating high-level diagrams from a single Blueprint graph automatically, you can use screenshots, exported images, or custom scripts to create a visual representation of the graph's structure and interactions. Manual annotation and organization can further help in communicating the high-level design to others.

Person:

- Can I use the Unreal Engine Python API to iterate over all the nodes in the blueprint graph?

ChatGPT:

- Yes, you can use the Unreal Engine Python API to iterate over all the nodes in a Blueprint graph. The Python API provides access to many of the engine's features and functions, allowing you to automate tasks and manipulate assets, including Blueprints.

Here's a basic example of how you can use the Python API to iterate over all the nodes in a Blueprint graph:

```python

import unreal

# Load the Blueprint asset
blueprint_asset_path = '/Game/MyBlueprints/MyBlueprint.MyBlueprint'
blueprint_asset = unreal.load_asset(blueprint_asset_path)

# Check if the asset is a Blueprint class
if blueprint_asset.is_a(unreal.Blueprint):
    # Get the Blueprint's UClass
    blueprint_class = unreal.BlueprintGeneratedClass.cast(blueprint_asset.GeneratedClass)

    # Get the default object of the UClass
    blueprint_default_object = unreal.get_default_object(blueprint_class)

    # Get the Blueprint's graph
    blueprint_graph = blueprint_default_object.get_blueprint_generated_script()

    # Iterate over all nodes in the graph
    for node in blueprint_graph.Nodes:
        # Print node's name and class
        print('Node Name: {}, Node Class: {}'.format(node.NodeName, node.get_class().get_name()))

        # Do something with the node...
```

Note that this example assumes that you have a valid Blueprint asset path. Replace `/Game/MyBlueprints/MyBlueprint.MyBlueprint` with the actual path to the Blueprint you want to work with.

Keep in mind that you may need to adjust the script depending on the specific details of your project and the version of Unreal Engine you are using. The Python API may change between versions, so consult the official Unreal Engine Python API documentation for the specific version you are using for more details and updated methods.

Person:

- I wrote a lot of c++ code for my game project built in Unreal Engine 5.1. I want to write unit-test for my code like I did with normal c++ projects. Is it possible?

ChatGPT:

- Yes, it is possible to write unit tests for your C++ code in Unreal Engine projects. Unreal Engine has an integrated testing framework called Unreal Automated Testing (UAT) that allows you to write unit tests, functional tests, and integration tests for your game.

For unit tests, you can use the Automation Testing framework to create test cases for your C++ code. Here's a basic example of how to create a simple unit test:

1. In your game's Source folder, create a new folder named "Tests" (if it doesn't already exist).
2. Inside the "Tests" folder, create a new C++ header file and a source file for your test suite, e.g., `MyGameUnitTest.h` and `MyGameUnitTest.cpp`.
3. In the header file, `MyGameUnitTest.h`, include the required headers and define your test suite class that inherits from `FAutomationTestBase`:

```cpp

#pragma once

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"

class FMyGameUnitTest : public FAutomationTestBase
{
public:
    FMyGameUnitTest(const FString& InName)
        : FAutomationTestBase(InName, false)
    {
    }

    // Add additional test cases here...

    virtual uint32 GetTestFlags() const override;
    virtual bool RunTest(const FString& Parameters) override;
};
```

1. In the source file, `MyGameUnitTest.cpp`, implement your test suite class and register your test cases:

```cpp

#include "Tests/MyGameUnitTest.h"

// Your game's includes here...

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyGameUnitTest, "MyGame.UnitTests", EAutomationTestFlags::EditorContext | EAutomationTestFlags::SmokeFilter)

uint32 FMyGameUnitTest::GetTestFlags() const
{
    return EAutomationTestFlags::EditorContext | EAutomationTestFlags::SmokeFilter;
}

bool FMyGameUnitTest::RunTest(const FString& Parameters)
{
    // Write your test cases here...

    // Example:
    // int32 result = MyGameFunction();
    // TestTrue("MyGameFunction should return 42", result == 42);

    return true;
}
```

1. After implementing your test cases, compile your project.
2. To run your tests, open the Unreal Editor and navigate to "Window" > "Developer Tools" > "Session Frontend." In the Session Frontend window, switch to the "Automation" tab, and you should see your test suite listed under "MyGame.UnitTests". Select your test suite and click "Run Tests" to execute your unit tests.

Remember to replace `MyGame` in the example with your actual game's name and add test cases relevant to your project. You can find more information about writing tests in Unreal Engine in the official documentation:

- [Automation Spec](https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/Automation/AutomationSpec/)
- [Unreal Engine Testing Guide](https://docs.unrealengine.com/4.27/en-US/ProductionPipelines/TestingAndOptimization/Testing/)

These resources should help you get started with writing unit tests for your C++ code in Unreal Engine projects.

Person:

- I can't find ""Developer Tools" in Window

ChatGPT:

- I apologize for the confusion. In Unreal Engine 5, the "Session Frontend" has been replaced with the "Test Automation" window. Here's how you can access it:

1. Open the Unreal Editor.
2. Go to "Window" in the top menu bar.
3. Select "Test Automation."

The "Test Automation" window should appear, and you can use it to run your automated tests. You'll find your test suite in the list, and you can select it and click "Run Tests" to execute your unit tests.

Person:

- Ok I found it.
Can I run these tests in command line? I'm asking this because I want to run these tests on my CI platform (GitHub CI runner).

ChatGPT:

- Yes, you can run your Unreal Engine automated tests from the command line. This is especially useful for integrating with CI platforms like GitHub Actions. To run your tests from the command line, you can use the following command:

```bash

PathToUE5Editor.exe -project="PathToYourProject.uproject" -ExecCmds="Automation RunTests MyGame.UnitTests" -ReportOutputPath="PathToTestResults" -Unattended -nopause -nullRHI -log
```

Replace `PathToUE5Editor.exe`, `PathToYourProject.uproject`, `MyGame.UnitTests`, and `PathToTestResults` with appropriate paths and names for your project.

Here's a breakdown of the command:

- `PathToUE5Editor.exe`: The path to your Unreal Engine 5 Editor executable.
- `-project="PathToYourProject.uproject"`: The path to your project's `.uproject` file.
- `-ExecCmds="Automation RunTests MyGame.UnitTests"`: The command to run your tests, where `MyGame.UnitTests` should be replaced with your test suite's name.
- `-ReportOutputPath="PathToTestResults"`: The path where the test results will be saved.
- `-Unattended`: Runs the tests without user intervention.
- `-nopause`: Ensures the tests don't pause on completion.
- `-nullRHI`: Disables the use of a rendering back-end, which can be useful for running tests on a CI platform without a GPU.
- `-log`: Enables logging during test execution.

After running the tests, you can find the test results in the specified `PathToTestResults` folder, which can then be used by your CI platform for further analysis or reporting.

To integrate with GitHub Actions, you'll need to set up a GitHub Actions workflow that checks out your project, sets up the environment with Unreal Engine, and runs the tests using the command line. You can find more information on setting up a GitHub Actions workflow in the [official documentation](https://docs.github.com/en/actions/learn-github-actions/introduction-to-github-actions) .

Person:

- I'm concerned that some of these tests require GPU and audio hardware, but the CI environment (i.e., GitHub actions) don't provide these hardware.

ChatGPT:

- It's true that CI environments like GitHub Actions typically don't provide GPU and audio hardware, which can be a limitation when running certain types of tests that require these resources. However, there are several approaches to handle this situation:

1. **Separate your tests** : Organize your tests into different categories or suites depending on their hardware requirements. You can run tests that don't require GPU and audio hardware on GitHub Actions, while running tests that require these resources on a local machine or a dedicated testing environment.
2. **Use a cloud-based testing service** : Some cloud-based testing services, like AWS Device Farm or Google Firebase Test Lab, provide virtual machines or devices with GPU and audio hardware for running tests. You can integrate these services into your CI pipeline to run tests that require specific hardware. Keep in mind that using these services might incur additional costs.
3. **Set up a self-hosted CI runner** : If your project requires GPU and audio hardware for testing, you can set up a self-hosted CI runner on a machine with the necessary hardware. GitHub Actions supports self-hosted runners, which allows you to run your tests on your own infrastructure. This approach requires more setup and maintenance, but it gives you full control over the hardware and software environment. You can learn more about self-hosted runners in the [official GitHub Actions documentation](https://docs.github.com/en/actions/hosting-your-own-runners/about-self-hosted-runners) .
4. **Use a CI platform with GPU support** : Some CI platforms, like GitLab CI/CD, CircleCI, or Jenkins, offer support for GPU-enabled environments or can be configured to run on machines with GPU and audio hardware. This might require additional configuration and possibly higher costs, but it can help you run the tests that need specific hardware in your CI pipeline.

By using one or a combination of these approaches, you can ensure that your tests are run in the appropriate environments, even when they require specific hardware like a GPU or audio device.

Person:

- In the example you gave me:

```c++
#include "Tests/MyGameUnitTest.h"

// Your game's includes here...

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyGameUnitTest, "MyGame.UnitTests", EAutomationTestFlags::EditorContext | EAutomationTestFlags::SmokeFilter)

uint32 FMyGameUnitTest::GetTestFlags() const
{
    return EAutomationTestFlags::EditorContext | EAutomationTestFlags::SmokeFilter;
}

bool FMyGameUnitTest::RunTest(const FString& Parameters)
{
    // Write your test cases here...

    // Example:
    // int32 result = MyGameFunction();
    // TestTrue("MyGameFunction should return 42", result == 42);

    return true;
}
```

How can I define individual test cases? How can I report errors in a structured way similar to xUnit?

ChatGPT:

- In Unreal Engine's Automation Testing framework, you can define individual test cases within the `RunTest` method of your test suite class. However, this framework doesn't follow the xUnit-style structure with separate test methods for each test case. Instead, you can use conditional statements to organize your test cases and report errors using the provided macros.

Here's an example of how to define individual test cases and report errors in a structured way:

```cpp

bool FMyGameUnitTest::RunTest(const FString& Parameters)
{
    // Test Case 1
    {
        int32 result = MyGameFunction1();
        TestTrue("MyGameFunction1 should return 42", result == 42);
    }

    // Test Case 2
    {
        FString result = MyGameFunction2();
        TestEqual("MyGameFunction2 should return 'Hello, World!'", result, TEXT("Hello, World!"));
    }

    // Test Case 3
    {
        bool result = MyGameFunction3();
        TestFalse("MyGameFunction3 should return false", result);
    }

    // Add more test cases here...

    return true;
}
```

In this example, each test case is wrapped in a separate scope using curly braces, which helps to organize your test cases and keep them separated. You can use the provided macros like `TestTrue`, `TestFalse`, and `TestEqual` to report errors in a structured way.

These macros automatically report errors with a description and file/line information, making it easier to locate and fix issues in your code. Additionally, you can use the `AddError` and `AddWarning` macros to report custom errors or warnings:

```cpp

AddError("My custom error message");
AddWarning("My custom warning message");
```

While this approach doesn't follow the exact structure of xUnit-style frameworks, it still provides a structured way to organize and report errors in your test cases using Unreal Engine's Automation Testing framework.

Person:

- In the method `FMyGameUnitTest::RunTest`, if my test logic depends on an established scene with Actors and Components, I need to setup the entire scene before running the test logic, right?

ChatGPT:

- Yes, you're correct. If your test logic depends on an established scene with Actors and Components, you'll need to set up the scene before running your tests in `FMyGameUnitTest::RunTest`. One way to achieve this is by creating a dedicated map (level) for your test scenarios, which you can load and set up before running the test cases. Here's how you can do that:

1. In the Unreal Editor, create a new map (level) specifically for your testing scenarios. Add the necessary Actors and Components to the map.
2. Save the map and take note of its asset path (e.g., `/Game/Maps/TestMap`).
3. In your `FMyGameUnitTest` class, override the `GetTestWorld()` method to specify the test map:

```cpp

virtual FString GetTestWorld() const override
{
    return TEXT("/Game/Maps/TestMap");
}
```

Replace `/Game/Maps/TestMap` with the actual path to your test map.

1. In the `FMyGameUnitTest::RunTest` method, you can now access the loaded test map and its Actors to perform your test logic:

```cpp

bool FMyGameUnitTest::RunTest(const FString& Parameters)
{
    // Access the test map's World
    UWorld* TestWorld = GetTestWorld();

    // Access Actors from the test map
    for (TActorIterator<AActor> ActorItr(TestWorld); ActorItr; ++ActorItr)
    {
        AActor* Actor = *ActorItr;
        
        // Perform test logic using the Actor...
    }

    // Add your test cases here...

    return true;
}
```

By following these steps, you can set up a scene with Actors and Components and use them in your test logic within the `FMyGameUnitTest::RunTest` method. This approach allows you to create specific testing scenarios and isolate them from the rest of your project.
