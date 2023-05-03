#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationEditorCommon.h"

// EditorContext defines that we want to be able to run this test in the Editor
// ProductFilter is for defining how long the test will take to run
// For more information check AutomationTest.h
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FFovTutorialTest,
	"Fov.Tutorial.Test",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

// Your function must be named RunTest
// The struct name here "FHeroTest" must match the one in the macro above
bool FFovTutorialTest::RunTest(const FString& Parameters)
{
	AddInfo(TEXT("SUCCESS **********************"));
	return true;
}
