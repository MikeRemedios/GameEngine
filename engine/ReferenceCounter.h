#pragma once

/*
* The ReferenceCounter class keeps track of how many things are referencing an object that inherits this class
*/
class ReferenceCounter
{
public:
	/*
	* Sets reference count to 1 when the object is created
	*/
	ReferenceCounter() :
		m_refCount(1) {}
	
	/*
	* Returns number of objects referencing this object
	* @return Referencing objects
	*/
	inline int GetReferenceCount() { return m_refCount; }

	/*
	* Increments referencing objects by 1
	*/
	inline void AddReference() { m_refCount++; }

	/*
	* Decrements referencing objects by 1
	* @return True if referencing objects is 0
	*/
	inline bool RemoveReference() { m_refCount--; return m_refCount == 0; }
protected:
private:
	/* Number of referencing objects */
	int m_refCount;
};