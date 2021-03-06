/*!\file CBaum.hpp
 * \brief
 *
 *  Created on: 01.06.2018
 *      Author: diamo
 */

#ifndef CBAUM_HPP_
#define CBAUM_HPP_
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
template <typename T> class CKnot;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T> class CBaum{
public:
	CBaum();
	~CBaum();
	void insert(T value);
	void inorder(std::ostream& os);
	void preorder(std::ostream& os);
	void postorder(std::ostream& os);
private:
	CKnot<T>* m_root;
	void deleteBaum(CKnot<T>* knot);
	void insert(T value, CKnot<T>* knot);
	void inorder(std::ostream& os, CKnot<T>* knot);
	void preorder(std::ostream& os, CKnot<T>* knot);
	void postorder(std::ostream& os, CKnot<T>* knot);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T> class CKnot{
	friend class CBaum<T>;
private:
	CKnot(T& value);
	~CKnot();

	CKnot* m_left;
	CKnot* m_right;
	T m_value;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
CBaum<T>::CBaum(){
	m_root = NULL;
}
template <typename T>
CBaum<T>::~CBaum(){
	deleteBaum(m_root);
}

template <typename T>
void CBaum<T>::insert(T value){
	insert(value, m_root);
}
template <typename T>
void CBaum<T>::insert(T value, CKnot<T>* knot){
	if(knot == NULL){
		m_root = new CKnot<T>(value);
	}
	else{
		if(value < knot->m_value){
			if(knot->m_left == NULL)
				knot->m_left = new CKnot<T>(value);
			else
				insert(value, knot->m_left);
		}else{
			if(knot->m_right == NULL)
				knot->m_right = new CKnot<T>(value);
			else
				insert(value, knot->m_right);
		}
	}
}
template <typename T>
void CBaum<T>::inorder(std::ostream& os){
	inorder(os, m_root);
}
template <typename T>
void CBaum<T>::inorder(std::ostream& os, CKnot<T>* knot){
	if(knot != NULL){
		inorder(os, knot->m_left);
		os << knot->m_value;
		inorder(os, knot->m_right);
	}
}
template <typename T>
void CBaum<T>::preorder(std::ostream& os){
	preorder(os, m_root);
}
template <typename T>
void CBaum<T>::preorder(std::ostream& os, CKnot<T>* knot){
	if(knot != NULL){
		os << knot->m_value;
		preorder(os, knot->m_left);
		preorder(os, knot->m_right);
	}
}
template <typename T>
void CBaum<T>::postorder(std::ostream& os){
	postorder(os, m_root);
}
template <typename T>
void CBaum<T>::postorder(std::ostream& os, CKnot<T>* knot){
	if(knot != NULL){
		postorder(os, knot->m_left);
		postorder(os, knot->m_right);
		os << knot->m_value;
	}
}

template <typename T>
void CBaum<T>::deleteBaum(CKnot<T>* knot){
	if(knot != NULL){
		deleteBaum(knot->m_left);
		deleteBaum(knot->m_right);
		delete knot;
		knot = NULL;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
CKnot<T>::CKnot(T& value){
	m_value = value;
	m_right = NULL;
	m_left = NULL;
}
template <typename T>
CKnot<T>::~CKnot(){
	m_left = NULL;
	m_right = NULL;

}


#endif /* CBAUM_HPP_ */
