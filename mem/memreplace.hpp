#ifndef memreplace_hpp__
#define memreplace_hpp__

///////////////////////////////////////////////////////////////////////////////////////////////////

namespace apilib
{
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  /**
   * [������] ������ ����� �������� ������ ������.
   *
   * ����� ����������� � ����� � 1 ����.
   * �������������� �������� ������������ ���������, ����� �� ��������� ��������.
   *
   * @param data      ������.
   * @param size      ������ ������.
   * @param old_value �������� ��� ������.
   * @param new_value �������� ��� ������ ������ ����������.
   *
   * @return ���������� �������������� ��������,
   *         0 ���� �� ������� �������� ��� ���������� ��� ��������� ������.
  */
  template<typename T>
  inline size_t __memreplace_x(void* data, size_t size, T old_value, T new_value)
  {
    size_t cnt = 0;

    if(data != NULL && size >= sizeof(T))
    {
      T* ptr = (T*)((unsigned char*)data);
      T* end = (T*)((unsigned char*)data + size - sizeof(T));

      while(ptr <= end)
      {
        if(*ptr == old_value)
        {
          *ptr = new_value;
          cnt = cnt + 1;
          ptr = (T*)((unsigned char*)ptr + sizeof(T)); 
        }
        else
        {
          ptr = (T*)((unsigned char*)ptr + 1);
        }
      }
    }

    return cnt;
  }

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
};

///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // memreplace_hpp__