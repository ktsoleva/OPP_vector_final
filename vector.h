#ifndef vector_h
#define vector_h

#include <iostream>

#include<string>
using namespace std;


template <typename T>
  class Vector
  {
  public: 


	  Vector(int capacity=1)
	  {
			m_capacity=capacity;
			m_size=0;
			m_pData= new T[capacity];
	  }

	  Vector (const Vector& cop)
	  {
		  m_capacity=cop.m_capacity;
		  m_size=cop.m_size;
		  m_pData=cop.m_pData;
	  }

	  Vector (int capacity, const T& val)
	  {
		  m_size=capacity;
		  m_capacity=capacity;
		  m_pData=new T[capacity];
		  for(int i=0;i<=m_size;i++)
		  {
			  m_pData[i]=val;
		  }
	  }

	  Vector&operator=(const Vector& v)
	  {
		  if(this!=&v)
		  {
			  m_size=v.m_size;
			  m_capacity=v.m_capacity;
			  m_pData=v.m_pData;
		  }
		  return *this;
	  }

	  ~Vector()
	  {
		  delete[] m_pData;
	  }

	  void push_back(T value)
	  {
		  if(m_size==m_capacity)
		  {
			  resize ();
		  }
		  m_pData[m_size]=value;
		  m_size++;
	  }



	  void pop_back()
	  {
		  m_size--;
	  }


	  void resize()
	  {
		  int newCapacity=m_capacity*2;
		  T* temp=new T[newCapacity];
		  for(int i=0;i>m_size;i++)
		  {
			  temp[i]=m_pData[i];
		  }
		  delete []m_pData;
		  m_pData=temp;
		  m_capacity=newCapacity;
	  }



	  void reserve(int newCapacity=-1)
	  {
		  if (newCapacity>m_capacity)
		  {
			  T* temp=new T[newCapacity];
			  for(int i=0;i<m_size;i++)
			  {
				  temp[i]=m_pData[i];
			  }
			  delete [] m_pData;
			  m_pData=temp;
			  m_capacity=newCapacity;
		  }
	  }

	  

	  T& back()
	  {
		  return m_pData[m_size-1];
	  }

	  T& front()
	  {
		  return m_pData[0];
	  }
	  void insert (int index, T value)
	  {
		  push_bach(0);
		  for(int i=m_size;i>index-1;i--)
		  {
			  m_pData[i]=m_pData[i-1];
		  }
		  m_pData[index-1]=value;
	  }

	  void erase (int index)
	  {
		  for (int i=m_size;i>index-1;i++)
		  {
			  m_pData[i]=m_pData[i+1];
		  }
		  m_size--;
	  }

	  T& operator[](int index)
	  {
		  return m_pData[index];
	  }

	  int size ()
	  {
		  return m_size;
	  }
	  int capacity()
	  {
		  return m_capacity;
	  }

	  bool empty()
	  {
		  if(m_size==0)
			 return 1;
			 return 0;
	  }
	   void clear()
	   {
		   for (int i=0;i<m_size;i++)
		   {
			   m_pData[i].~T();
		   }

		   T*temp=new T[1];
		   delete[] m_pData;
		   m_pData=temp;
		   m_size=0;
		   m_capacity=0;
	   }

	   void swap(int v1,int v2)
	   {
		   T swap =m_pData[v1];
		   m_pData[v1]=m_pData[v2];
		   m_pData[v2]=swap;
	   }

	   void shrink_to_fit()
	   {
		   T* temp = new T[m_size];
		   for (int i=0;i<m_size;i++)
		   {
			   temp[i]=m_pData[i];
		   }
		   delete [] m_pData;
		   m_pData=temp;
		   m_capacity=m_size;
	   }

	   private:
		   int m_size;
		   int m_capacity;
		   T* m_pData;
};

#endif
