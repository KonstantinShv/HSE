#include "rccregisters.hpp"
#include "gpiocregisters.hpp"
#include <iostream>


int main()
{  
    
  
  
  RCC::CR::HSEON::On::Set();
  
  while(!RCC::CR::HSERDY::Ready::IsSet())
  {
  }
  
    
  
  RCC::CFGR::SW::Hse::Set();
  while(!RCC::CFGR::SWS::Hse::IsSet())
  {
  }
  
 
  RCC::CR::HSION::Off::Set();

  
  
  RCC::AHB1ENR::GPIOCEN::Enable::Set();
  //������ ������������ �� ���� �
   //*reinterpret_cast<std::uint32_t *>(0x40023830) = 1U << 2U ;    
  //��������� PortC.5 �� �����. ������� PortC.MODER5, ����� ��. https://www.st.com/resource/en/datasheet/stm32f411re.pdf  ��� 54
  // �������� �������� �� https://www.st.com/resource/en/reference_manual/dm00119316-stm32f411xce-advanced-armbased-32bit-mcus-stmicroelectronics.pdf ���. 157
  //*reinterpret_cast<std::uint32_t *>(0x40020800) = 1U << 10U;
  GPIOC::MODER::MODER5::Output::Set();
  for(;;)
  {
    for (int i = 0; i < 1000000; i ++)
    {
    }
    GPIOC::ODR::ODR5::High::Set();
  //������� 1 � PortC.5. ������� ODR � https://www.st.com/resource/en/reference_manual/dm00119316-stm32f411xce-advanced-armbased-32bit-mcus-stmicroelectronics.pdf ���. 159
  //*reinterpret_cast<std::uint32_t *>(0x40020814) = 1U << 5U;
  //GPIOC::ODR::ODR5::Low::Set();
    for (int i = 0; i < 1000000; i ++)
    {
    }
    GPIOC::ODR::ODR5::Low::Set();
  }
  return 1;
}
