// DRAFT FILE

#pragma #pragma message(__FILE__ " is a draft file!") 

#include <gmock/gmock.h>

class Sample
{
    virtual void DoThis() = 0;
    virtual bool DoThat(int n, double x) = 0;
};

template <typename E>
class SampleTemplateClass
{
  public:
    virtual int GetSize() const = 0;
};

class MockSample : public Sample
{
  public:
    MOCK_METHOD0(DoThis, void());
    MOCK_METHOD2(DoThat, bool(int n, double x));
};

template <typename E>
class MockSampleTemplateClass : public SampleTemplateClass
{
  public:
    MOCK_METHOD0_T(GetSize, int());
};

MockSample mock_sample;
