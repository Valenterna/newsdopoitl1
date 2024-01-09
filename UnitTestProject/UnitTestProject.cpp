#include "../bank.h"
#include "../processing.h"
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestProject
{

	bank* build_bank(float sale, float purchase)
	{
		bank* bank = new bank;
		bank->purchase = purchase;
		bank->sale = sale;
		return bank;
	}

	TEST_CLASS(UnitTestProject)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			bank* bank = build_bank(1, 2);
			Assert::AreEqual(1, process(bank));
		}
	};
}
