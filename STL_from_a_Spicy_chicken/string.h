#ifndef _MYSTRING_H
#define _MYSTRING_H

#include<stdexcept>
//声明
namespace Mystd {
	template<class val_type>
	class basic_string {
		using size_type = size_t;
	private:
		val_type* _source;
		size_type _capacity;
	public:
		//默认构造函数。构造空 string （拥有零大小和17的容量）
		basic_string();
		//构造拥有字符 ch 的 count 个副本的 string 
		basic_string(size_type count, val_type ch = '\0');
		//复制构造函数.以other的子串[pos, pos+count)构造string.若count==npos或未指定count,或若请求的子串越过字符串的结尾,则产生的子串为[pos,other.size())
		basic_string(const basic_string& other, size_type pos = 0, size_type count = npos);
		//以s所指向的字符串的首count个字符构造string s能包含空字符.若count大于s长度,则产生的字串为原字符串s
		basic_string(const val_type* s, size_type count = npos);
		//移动构造函数.用移动语义构造拥有other内容的string
		basic_string(basic_string&& other)noexcept;
		//析构函数
		~basic_string();
		//以str的副本替换内容
		basic_string& operator=(const basic_string& str);
		//用移动语义以str的内容替换内容
		basic_string& operator=(basic_string&& str)noexcept;
		//以s所指向的空终止字符串的内容替换内容
		basic_string& operator=(const val_type* s);
		//以字符ch的内容替换内容
		basic_string& operator=(val_type ch);
		//返回到位于指定位置pos的字符的引用.进行边界检查,非法访问时抛出std::out_of_range类型的异常
		val_type& at(size_type pos);
		const val_type& at(size_type pos) const;
		//在pos<size()时返回到位于指定位置pos的字符的引用,不进行边界检查
		val_type& operator[](size_type pos);
		const val_type& operator[](size_type pos) const;
		//返回到string中首字符的引用.若empty()==true则行为未定义
		val_type& front();
		const val_type& front() const;
		//返回到string中末字符的引用.若empty()==true则行为未定义
		val_type& back();
		const val_type& back() const;
		//返回指向拥有数据等价于存储于字符串中的空终止字符数组的指针
		const val_type* c_str() const noexcept;
		//检查 string 是否无字符
		bool empty() const noexcept;
		//返回string中的val_type元素数
		size_type size() const noexcept;
		size_type length() const noexcept;
		//返回当前已为字符串分配空间的字符数
		size_type capacity() const noexcept;
		//告诉basic_string对象大小的有计划更改,使得它能准确地管理存储分配
		//若new_cap大于当前capacity(),则分配新存储,并令capacity()大于或等于new_cap
		//若new_cap小于当前capacity(),则这是非强制的收缩请求
		//若new_cap小于当前size(),则这是非强制的收缩到适合(shrink-to-fit)请求,等价于shrink_to_fit()
		void reserve(size_type new_cap = 0);
		//请求移除未使用的容量,减少capacity()到size() 
		void shrink_to_fit();
		//从string移除所有字符
		void clear() noexcept;
		//在位置index插入count个字符ch的副本
		basic_string& insert(size_type index, size_type count, val_type ch);
		//在位置index插入s所指向的空终止字符串
		basic_string& insert(size_type index, const val_type* s);
		//在位置index插入范围[s,s+count)中的字符,范围能含有空字符
		basic_string& insert(size_type index, const val_type* s, size_type count);
		//在位置index插入由str.substr(index_str,count)获得的字符串
		basic_string& insert(size_type index, const basic_string& str, size_type index_str = 0, size_type count = npos);
		//移除从index开始的std::min(count,size()-index)个字符
		basic_string& erase(size_type index = 0, size_type count = 1);
		//后附给定字符ch到字符串尾
		void push_back(val_type ch);
		//从字符串移除末字符
		void pop_back();
		//后附count个ch的副本
		basic_string& append(size_type count, val_type ch);
		//后附str的子串[pos,pos+count).若请求的子串越过string结尾,或若count==npos,则后附的子串为[pos,size()).若pos>str.size(),则抛出std::out_of_range
		basic_string& append(const basic_string& str, size_type pos = 0, size_type count = npos);
		//后附范围[s,s+count)中的字符.此范围能含有空字符
		basic_string& append(const val_type* s, size_type count);
		//后附s所指向的空终止字符串
		basic_string& append(const val_type* s);
		//后附string str
		basic_string& operator+=(const basic_string& str);
		//后附字符ch 
		basic_string& operator+=(val_type ch);
		//后附s所指向的空终止字符串
		basic_string& operator+=(const val_type* s);
		//比较此字符串与str
		int compare(const basic_string& str) const noexcept;
		//比较此字符串的[pos1,pos1+count1)子串与str.如果count1>size()-pos1,那么子串是[pos1,size()) 
		int compare(size_type pos1, size_type count1, const basic_string& str) const;
		//比较此字符串的[pos1,pos1+count1)子串与str的子串[pos2,pos2+count2).如果count1>size()-pos1,那么第一子串是[pos1,size()).如果count2>str.size()-pos2,那么第二子串是[pos2,str.size())
		int compare(size_type pos1, size_type count1, const basic_string& str, size_type pos2, size_type count2 = npos) const;
		//比较此字符串与始于 s 所指向的空终止字符序列
		int compare(const val_type* s) const;
		//比较此字符串的[pos1,pos1+count1)子串与始于s所指向的空终止字符序列.如果count1>size()-pos1,那么子串是[pos1,size())
		int compare(size_type pos1, size_type count1, const val_type* s) const;
		//比较此字符串的[pos1,pos1+count1)子串与范围[s,s+count2)中的字符.(注意:范围[s,s+count2)中的字符可包含空字符)
		int compare(size_type pos1, size_type count1, const val_type* s, size_type count2) const;
		//以string str替换[pos, pos + count)所指示的string部分
		basic_string& replace(size_type pos, size_type count, const basic_string& str);
		//以str的子串[pos2,pos2+count2)替换[pos,pos+count)所指示的string部分
		basic_string& replace(size_type pos, size_type count, const basic_string& str, size_type pos2, size_type count2 = npos);
		//以范围[cstr,cstr+count2)中的字符替换[pos,pos+count)所指示的string部分
		basic_string& replace(size_type pos, size_type count, const val_type* cstr, size_type count2);
		//以范围[cstr,cstr+length(cstr))中的字符替换[pos,pos+count)所指示的string部分
		basic_string& replace(size_type pos, size_type count, const val_type* cstr);
		//以字符ch的count2个副本替换[pos,pos+count)所指示的string部分
		basic_string& replace(size_type pos, size_type count, size_type count2, val_type ch);
		//返回子串[pos,pos+count).若请求的字串越过字符串的结尾,即count大于size()-pos(例如若count==npos),则返回的子串为[pos, size())
		basic_string substr(size_type pos = 0, size_type count = npos) const;
		//复制子串 [pos,pos+count)到dest所指向的字符串.若请求的子串越过string结尾,或若count==npos,则复制的子串为[pos,size()).产生的字符串不是空终止的.若pos>size(),则抛出std::out_of_range
		size_type copy(val_type* dest, size_type pos, size_type count) const;
		//重设string大小以含count个字符.若当前大小小于count,则后附额外的字符.若当前大小大于count,则缩减string到为其首count个元素
		void resize(size_type count, val_type ch = '\0');
		//交换string与other的内容
		void swap(basic_string& other);
		////寻找等于 str 的首个子串.搜索始于pos,即找到的子串必须不始于pos之前的位置
		//size_type find(const basic_string& str, size_type pos = 0) const noexcept;
		////寻找等于范围[s,s+count)的首个子串.此范围能含空字符.搜索始于pos,即找到的子串必须不始于pos之前的位置
		//size_type find(const val_type* s, size_type pos, size_type count) const;
		////寻找等于s所指向的字符串的首个子串.由首个空字符确定字符串长度.搜索始于pos,即找到的子串必须不始于pos之前的位置
		//size_type find(const val_type* s, size_type pos = 0) const;
		////寻找首个字符ch.搜索始于pos,即找到的子串必须不始于pos之前的位置
		//size_type find(val_type ch, size_type pos = 0) const noexcept;
		////寻找等于str的最后子串.搜索始于pos,即找到的子串必须不始于pos后的位置.若将npos或任何不小于size()-1的值作为pos传递,则在整个字符串中搜索
		//size_type rfind(const basic_string& str, size_type pos = npos) const noexcept;
		////寻找等于范围[s,s+count)的最后子串.此范围能包含空字符.搜索始于pos,即找到的子串必须不始于pos后的位置.若将npos或任何不小于size()-1的值作为pos传递,则在整个字符串中搜索
		//size_type rfind(const val_type* s, size_type pos, size_type count) const;
		////寻找等于s所指向的字符串的最后子串.由首个空字符确定字符串长度。.搜索始于pos,即找到的子串必须不始于pos后的位置.若将npos或任何不小于size()-1的值作为pos传递,则在整个字符串中搜索
		//size_type rfind(const val_type* s, size_type pos = npos) const;
		////寻找等于ch的最后字符.搜索始于pos,即找到的子串必须不始于pos后的位置.若将npos或任何不小于size()-1的值作为pos传递,则在整个字符串中搜索
		//size_type rfind(val_type ch, size_type pos = npos) const noexcept;
		////标准输入重载
		//std::istream& operator>>(std::istream& in);
		//标准输出重载
		std::ostream& operator<<(std::ostream& out);
		//这是特殊值,等于size_type类型可表示的最大值.准确含义依赖于语境,但通常,期待string下标的函数以之为字符串尾指示器,返回string下标的函数以之为错误指示器
		static const size_type npos = -1;
	};

	using string = basic_string<char>;
	using wstring = basic_string<wchar_t>;
}

//声明
namespace std {
	template<class val_type>
	Mystd::basic_string<val_type> operator+(const Mystd::basic_string<val_type>& lhs, const Mystd::basic_string<val_type>& rhs);
	template<class val_type>
	Mystd::basic_string<val_type> operator+(const Mystd::basic_string<val_type>& lhs, const val_type* rhs);
	template<class val_type>
	Mystd::basic_string<val_type> operator+(const Mystd::basic_string<val_type>& lhs, const val_type rhs);
	template<class val_type>
	Mystd::basic_string<val_type> operator+(const val_type* lhs, const Mystd::basic_string<val_type>& rhs);
	template<class val_type>
	Mystd::basic_string<val_type> operator+(const val_type lhs, const Mystd::basic_string<val_type>& rhs);
	template< class val_type>
	void swap(Mystd::basic_string<val_type>& lhs, Mystd::basic_string<val_type>& rhs);
	//template< class val_type>
	//istream& operator>>(istream& in, Mystd::basic_string<val_type>& str);
	template< class val_type>
	ostream& operator<<(ostream& out, Mystd::basic_string<val_type>& str);
}

//定义
namespace Mystd {
	template<class val_type>
	basic_string<val_type>::basic_string() {
		_capacity = 17;
		_source = new val_type[_capacity + 1];
		memset(_source, '\0', _capacity);
		_source[_capacity] = '\0';
	}
	template<class val_type>
	basic_string<val_type>::basic_string(size_type count, val_type ch) {
		_capacity = count;
		_source = new val_type[_capacity + 1];
		memset(_source, ch, _capacity);
		_source[_capacity] = '\0';
	}
	template<class val_type>
	basic_string<val_type>::basic_string(const basic_string& other, size_type pos, size_type count) {
		size_type  o_len = other.length();
		if (pos >= o_len) {
			throw std::out_of_range("pos位置大于等于other长度");
			return;
		}
		if (count == npos || pos + count > o_len) {
			_capacity = o_len - pos;
		}
		else {
			_capacity = count;
		}
		_source = new val_type[_capacity + 1];
		memcpy(_source, other._source + pos, _capacity);
		_source[_capacity] = '\0';
	}
	template<class val_type>
	basic_string<val_type>::basic_string(const val_type* s, size_type count) {
		size_type s_len = strlen(s);
		if (count >= s_len) {
			_capacity = s_len;
		}
		else {
			_capacity = count;
		}
		_source = new val_type[_capacity + 1];
		memcpy(_source, s, _capacity);
		_source[_capacity] = '\0';
	}
	template<class val_type>
	basic_string<val_type>::basic_string(basic_string&& other)noexcept {
		_capacity = other._capacity;
		_source = new val_type[_capacity + 1];
		memcpy(_source, other._source, _capacity);
		_source[_capacity] = '\0';
	}
	template<class val_type>
	basic_string<val_type>::~basic_string() {
		delete[] _source;
		_source = nullptr;
	}
	template<class val_type>
	basic_string<val_type>& basic_string<val_type>::operator=(const basic_string<val_type>& str) {
		_capacity = str._capacity;
		delete[] _source;
		_source = new val_type[_capacity + 1];
		memcpy(_source, str._source, _capacity);
		_source[_capacity] = '\0';
		return *this;
	}
	template<class val_type>
	basic_string<val_type>& basic_string<val_type>::operator=(basic_string<val_type>&& str)noexcept {
		_capacity = str._capacity;
		delete[] _source;
		_source = new val_type[_capacity + 1];
		memcpy(_source, str._source, _capacity);
		_source[_capacity] = '\0';
		return *this;
	}
	template<class val_type>
	basic_string<val_type>& basic_string<val_type>::operator=(const val_type* s) {
		_capacity = strlen(s);
		delete[] _source;
		_source = new val_type[_capacity + 1];
		memcpy(_source, s, _capacity);
		_source[_capacity] = '\0';
		return *this;
	}
	template<class val_type>
	basic_string<val_type>& basic_string<val_type>::operator=(val_type ch) {
		_capacity = 1;
		delete[] _source;
		_source = new val_type[_capacity + 1];
		_source[0] = ch;
		_source[_capacity] = '\0';
		return *this;
	}
	template<class val_type>
	val_type& basic_string<val_type>::at(size_type pos) {
		if (pos >= length()) {
			throw std::out_of_range("pos>=length()越界");
			return _source[0];
		}
		return _source[pos];
	}
	template<class val_type>
	const val_type& basic_string<val_type>::at(size_type pos) const {
		if (pos >= length()) {
			throw std::out_of_range("pos>=length()越界");
			return _source[0];
		}
		return _source[pos];
	}
	template<class val_type>
	val_type& basic_string<val_type>::operator[](size_type pos) {
		return _source[pos];
	}
	template<class val_type>
	const val_type& basic_string<val_type>::operator[](size_type pos) const {
		return _source[pos];
	}
	template<class val_type>
	val_type& basic_string<val_type>::front() {
		return _source[0];
	}
	template<class val_type>
	const val_type& basic_string<val_type>::front() const {
		return _source[0];
	}
	template<class val_type>
	val_type& basic_string<val_type>::back() {
		return _source[length() - 1];
	}
	template<class val_type>
	const val_type& basic_string<val_type>::back() const {
		return _source[length() - 1];
	}
	template<class val_type>
	const val_type* basic_string<val_type>::c_str()const noexcept {
		return _source;
	}
	template<class val_type>
	bool basic_string<val_type>::empty() const noexcept {
		return _capacity == 0 || _source[0] == '\0';
	}
	template<class val_type>
	typename basic_string<val_type>::size_type basic_string<val_type>::size()const noexcept {
		return strlen(_source);
	}
	template<class val_type>
	typename basic_string<val_type>::size_type basic_string<val_type>::length()const noexcept {
		return strlen(_source);
	}
	template<class val_type>
	typename basic_string<val_type>::size_type basic_string<val_type>::capacity()const noexcept {
		return _capacity;
	}
	template<class val_type>
	void basic_string<val_type>::reserve(size_type new_cap) {
		size_type m_len = length();

		if (new_cap > _capacity) {
			//new_cap>_capacity
			_capacity = new_cap;
		}
		else if (new_cap < m_len) {
			//new_cap<size
			_capacity = m_len;
		}
		else {
			//size<new_cap<_capacity
			_capacity = new_cap;
		}
		val_type* buf = new val_type[m_len];
		memcpy(buf, _source, m_len);

		delete[] _source;

		_source = new val_type[_capacity + 1];
		memset(_source, '\0', _capacity);
		_source[_capacity] = '\0';
		memcpy(_source, buf, m_len);
	}
	template<class val_type>
	void basic_string<val_type>::shrink_to_fit() {
		size_type m_len = length();
		val_type* buf = new val_type[m_len];
		memcpy(buf, _source, m_len);
		delete[] _source;
		_capacity = m_len;
		_source = new val_type[_capacity + 1];
		memcpy(_source, buf, m_len);
		delete[] buf;
		buf = nullptr;
	}
	template<class val_type>
	void basic_string<val_type>::clear()noexcept {
		memset(_source, '\0', _capacity);
		_source[_capacity] = '\0';
	}
	template<class val_type>
	basic_string<val_type>& basic_string<val_type>::insert(size_type index, size_type count, val_type ch) {
		size_type m_len = length();
		while (m_len + count > _capacity)
			_capacity <<= 1;
		val_type* buf = new val_type[m_len];
		memcpy(buf, _source, m_len);
		_source = new val_type[_capacity + 1];
		memset(_source, '\0', _capacity);
		_source[_capacity] = '\0';
		memcpy(_source, buf, index);
		memset(_source + index, ch, count);
		memcpy(_source + index + count, buf + index, m_len - index);
		delete[] buf;
		buf = nullptr;
		return *this;
	}
	template<class val_type>
	basic_string<val_type>& basic_string<val_type>::insert(size_type index, const val_type* s) {
		size_type m_len = length();
		size_type s_len = strlen(s);
		while (m_len + s_len > _capacity)
			_capacity <<= 1;
		val_type* buf = new val_type[m_len];
		memcpy(buf, _source, m_len);
		delete[] _source;
		_source = new val_type[_capacity + 1];
		memset(_source, '\0', _capacity);
		_source[_capacity] = '\0';
		memcpy(_source, buf, index);
		memcpy(_source + index, s, s_len);
		memcpy(_source + index + s_len, buf + index, m_len - index);
		delete[]buf;
		buf = nullptr;
		return *this;
	}
	template<class val_type>
	basic_string<val_type>& basic_string<val_type>::insert(size_type index, const val_type* s, size_type count) {
		size_type m_len = length();
		while (m_len + count > _capacity)
			_capacity <<= 1;
		val_type* buf = new val_type[m_len];
		memcpy(buf, _source, m_len);
		delete[]_source;
		_source = new val_type[_capacity + 1];
		memset(_source, '\0', _capacity);
		_source[_capacity] = '\0';
		memcpy(_source, buf, index);
		memcpy(_source + index, s, count);
		memcpy(_source + index + count, buf + index, m_len - index);
		delete[] buf;
		buf = nullptr;
		return *this;
	}
	template<class val_type>
	basic_string<val_type>& basic_string<val_type>::insert(size_type index, const basic_string& str, size_type index_str, size_type count) {
		size_type m_len = length();
		size_type s_len = str.length();
		if (count == npos || s_len <= index_str + count)
			count = s_len - index_str;
		while (m_len + count > _capacity)
			_capacity <<= 1;
		val_type* buf = new val_type[m_len];
		memcpy(buf, _source, m_len);
		delete[]_source;
		_source = new val_type[_capacity + 1];
		memset(_source, '\0', _capacity);
		_source[_capacity] = '\0';
		memcpy(_source, buf, index);
		memcpy(_source + index, str._source, count);
		memcpy(_source + index + count, buf + index, m_len - index);
		delete[] buf;
		buf = nullptr;
		return *this;
	}
	template<class val_type>
	basic_string<val_type>& basic_string<val_type>::erase(size_type index, size_type count) {
		size_type m_len = length();
		if (index >= m_len) {
			throw std::out_of_range("index>=length()越界");
			return *this;
		}
		if (count == npos || index + count > m_len) {
			count = m_len - index;
		}
		memcpy(_source + index, _source + index + count, m_len - index - count);
		memset(_source + m_len - count, '\0', count);
		return *this;
	}
	template<class val_type>
	void basic_string<val_type>::push_back(val_type ch) {
		size_type m_len = length();
		if (m_len + 1 > _capacity) {
			while (m_len + 1 > _capacity)
				_capacity <<= 1;
			val_type* buf = new val_type[m_len];
			memcpy(buf, _source, m_len);
			delete[]_source;
			_source = new val_type[_capacity + 1];
			memset(_source, '\0', _capacity);
			_source[_capacity] = '\0';
			memcpy(_source, buf, m_len);
			delete[]buf;
			buf = nullptr;
		}
		_source[m_len] = ch;
	}
	template<class val_type>
	void basic_string<val_type>::pop_back() {
		size_type m_len = length();
		if (m_len == 0)
		{
			throw std::out_of_range("size == 0越界");
			return;
		}
		_source[m_len - 1] = '\0';
	}
	template<class val_type>
	basic_string<val_type>& basic_string<val_type>::append(size_type count, val_type ch) {
		size_type m_len = length();
		if (m_len + count > _capacity) {
			while (m_len + count > _capacity)
				_capacity <<= 1;
			val_type* buf = new val_type[m_len];
			memcpy(buf, _source, m_len);
			delete[]_source;
			_source = new val_type[_capacity + 1];
			memset(_source, '\0', _capacity);
			_source[_capacity] = '\0';
			memcpy(_source, buf, m_len);
			delete[]buf;
			buf = nullptr;
		}
		memset(_source + m_len, ch, count);
		return *this;
	}
	template<class val_type>
	basic_string<val_type>& basic_string<val_type>::append(const basic_string& str, size_type pos, size_type count) {
		size_type s_len = str.length();
		if (pos >= s_len) {
			throw std::out_of_range("pos>=str.length()越界");
			return *this;
		}
		size_type m_len = length();
		if (count == npos || pos + count > s_len)
			count = s_len - pos;
		if (m_len + count > _capacity) {
			while (m_len + count > _capacity)
				_capacity <<= 1;
			val_type* buf = new val_type[m_len];
			memcpy(buf, _source, m_len);
			delete[]_source;
			_source = new val_type[_capacity + 1];
			memset(_source, '\0', _capacity);
			_source[_capacity] = '\0';
			memcpy(_source, buf, m_len);
			delete[]buf;
			buf = nullptr;
		}
		memcpy(_source + m_len, str._source + pos, count);
		return *this;
	}
	template<class val_type>
	basic_string<val_type>& basic_string<val_type>::append(const val_type* s, size_type count) {
		size_type m_len = length();
		if (m_len + count > _capacity) {
			while (m_len + count > _capacity)
				_capacity <<= 1;
			val_type* buf = new val_type[m_len];
			memcpy(buf, _source, m_len);
			delete[]_source;
			_source = new val_type[_capacity + 1];
			memset(_source, '\0', _capacity);
			_source[_capacity] = '\0';
			memcpy(_source, buf, m_len);
			delete[]buf;
			buf = nullptr;
		}
		memcpy(_source + m_len, s, count);
		return *this;
	}
	template<class val_type>
	basic_string<val_type>& basic_string<val_type>::append(const val_type* s) {
		size_type m_len = length();
		size_type s_len = strlen(s);
		if (m_len + s_len > _capacity) {
			while (m_len + s_len > _capacity)
				_capacity <<= 1;
			val_type* buf = new val_type[m_len];
			memcpy(buf, _source, m_len);
			delete[]_source;
			_source = new val_type[_capacity + 1];
			memset(_source, '\0', _capacity);
			_source[_capacity] = '\0';
			memcpy(_source, buf, m_len);
			delete[]buf;
			buf = nullptr;
		}
		memcpy(_source + m_len, s, s_len);
		return *this;
	}
	template<class val_type>
	basic_string<val_type>& basic_string<val_type>::operator+=(const basic_string& str) {
		return append(str);
	}
	template<class val_type>
	basic_string<val_type>& basic_string<val_type>::operator+=(val_type ch) {
		return append(1, ch);
	}
	template<class val_type>
	basic_string<val_type>& basic_string<val_type>::operator+=(const val_type* s) {
		return append(s);
	}
	template<class val_type>
	int basic_string<val_type>::compare(const basic_string& str)const noexcept {
		size_type m_len = length();
		size_type s_len = str.length();
		size_type c_len = std::min(m_len, s_len);
		for (size_type i = 0; i < c_len; ++i) {
			if (_source[i] != str._source[i]) {
				return _source[i] < str._source[i] ? -1 : 1;
			}
		}
		if (m_len != s_len)
			return c_len == m_len ? -1 : 1;
		else
			return 0;
	}
	template<class val_type>
	int basic_string<val_type>::compare(size_type pos1, size_type count1, const basic_string& str)const {
		size_type m_len = this->length();
		if (pos1 >= m_len) {
			throw std::out_of_range("pos1>=this->length()越界");
			return -2;
		}
		size_type s_len = str.length();
		if (pos1 + count1 > m_len)count1 = m_len - pos1;
		size_type c_len = std::min(count1, s_len);
		for (size_type i = 0; i < c_len; ++i) {
			if (_source[pos1 + i] != str._source[i]) {
				return _source[pos1 + i] < str._source[i] ? -1 : 1;
			}
		}
		if (count1 != s_len)
			return c_len == count1 ? -1 : 1;
		else
			return 0;
	}
	template<class val_type>
	int basic_string<val_type>::compare(size_type pos1, size_type count1, const basic_string& str, size_type pos2, size_type count2)const {
		size_type m_len = this->length();
		if (pos1 >= m_len) {
			throw std::out_of_range("pos1>=this->length()越界");
			return -2;
		}
		size_type s_len = str.length();
		if (pos2 >= s_len) {
			throw std::out_of_range("pos2>=str->length()越界");
			return -2;
		}
		if (count1 == npos || pos1 + count1 > m_len)count1 = m_len - pos1;
		if (count2 == npos || pos2 + count2 > s_len)count2 = s_len - pos2;
		size_type c_len = std::min(count1, count2);
		for (size_type i = 0; i < c_len; ++i) {
			if (_source[pos1 + i] != str._source[pos2 + i]) {
				return _source[pos1 + i] < str._source[pos2 + i] ? -1 : 1;
			}
		}
		if (count1 != count2)
			return c_len == count1 ? -1 : 1;
		else
			return 0;
	}
	template<class val_type>
	int basic_string<val_type>::compare(const val_type* s)const {
		size_type m_len = length();
		size_type s_len = strlen(s);
		size_type c_len = std::min(m_len, s_len);
		for (size_type i = 0; i < c_len; ++i) {
			if (_source[i] != s[i]) {
				return _source[i] < s[i] ? -1 : 1;
			}
		}
		if (m_len != s_len)
			return c_len == m_len ? -1 : 1;
		else
			return 0;
	}
	template<class val_type>
	int basic_string<val_type>::compare(size_type pos1, size_type count1, const val_type* s)const {
		size_type m_len = this->length();
		if (pos1 >= m_len) {
			throw std::out_of_range("pos1>=this->length()越界");
			return -2;
		}
		size_type s_len = strlen(s);
		if (pos1 + count1 > m_len)count1 = m_len - pos1;
		size_type c_len = std::min(count1, s_len);
		for (size_type i = 0; i < c_len; ++i) {
			if (_source[pos1 + i] != s[i]) {
				return _source[pos1 + i] < s[i] ? -1 : 1;
			}
		}
		if (count1 != s_len)
			return c_len == count1 ? -1 : 1;
		else
			return 0;
	}
	template<class val_type>
	int basic_string<val_type>::compare(size_type pos1, size_type count1, const val_type* s, size_type count2)const {
		size_type m_len = this->length();
		if (pos1 >= m_len) {
			throw std::out_of_range("pos1>=this->length()越界");
			return -2;
		}
		size_type s_len = strlen(s);
		if (pos1 + count1 > m_len)count1 = m_len - pos1;
		size_type c_len = std::min(count1, count2);
		for (size_type i = 0; i < c_len; ++i) {
			if (_source[pos1 + i] != s[i]) {
				return _source[pos1 + i] < s[i] ? -1 : 1;
			}
		}
		if (count1 != count2)
			return c_len == count1 ? -1 : 1;
		else
			return 0;
	}
	template<class val_type>
	basic_string<val_type>& basic_string<val_type>::replace(size_type pos, size_type count, const basic_string<val_type>& str) {
		size_type m_len = length();
		if (pos >= m_len) {
			throw std::out_of_range("pos>=m_len越界");
			return *this;
		}
		if (pos + count > m_len)count = m_len - pos;
		size_type s_len = str.length();
		if (count < s_len && m_len + s_len - count > _capacity) {
			while (m_len + s_len - count > _capacity)
				_capacity <<= 1;
			val_type* buf = new val_type[m_len];
			memcpy(buf, _source, m_len);
			delete[]_source;
			_source = new val_type[_capacity + 1];
			memset(_source, '\0', _capacity);
			_source[_capacity] = '\0';
			memcpy(_source, buf, m_len);
		}
		memcpy(_source + pos + s_len, _source + pos + count, m_len - pos - count);
		memcpy(_source + pos, str._source, s_len);
		return *this;
	}
	template<class val_type>
	basic_string<val_type>& basic_string<val_type>::replace(size_type pos, size_type count, const basic_string<val_type>& str, size_type pos2, size_type count2) {
		size_type m_len = length();
		if (pos >= m_len) {
			throw std::out_of_range("pos>=m_len越界");
			return *this;
		}
		size_type s_len = str.length();
		if (pos2 >= s_len) {
			throw std::out_of_range("pos2>=s_len越界");
			return *this;
		}
		if (count == npos || pos + count > m_len)count = m_len - pos;
		if (count2 == npos || pos2 + count2 > s_len)count2 = s_len - pos2;
		if (count < count2 && m_len + count2 - count > _capacity) {
			while (m_len + count2 - count > _capacity)
				_capacity <<= 1;
			val_type* buf = new val_type[m_len];
			memcpy(buf, _source, m_len);
			delete[]_source;
			_source = new val_type[_capacity + 1];
			memset(_source, '\0', _capacity);
			_source[_capacity] = '\0';
			memcpy(_source, buf, m_len);
		}
		memcpy(_source + pos + count2, _source + pos + count, m_len - pos - count);
		memcpy(_source + pos, str._source + pos2, count2);
		return *this;
	}
	template<class val_type>
	basic_string<val_type>& basic_string<val_type>::replace(size_type pos, size_type count, const val_type* cstr, size_type count2) {
		size_type m_len = length();
		if (pos >= m_len) {
			throw std::out_of_range("pos>=m_len越界");
			return *this;
		}
		if (pos + count > m_len)count = m_len - pos;
		if (count < count2 && m_len + count2 - count > _capacity) {
			while (m_len + count2 - count > _capacity)
				_capacity <<= 1;
			val_type* buf = new val_type[m_len];
			memcpy(buf, _source, m_len);
			delete[]_source;
			_source = new val_type[_capacity + 1];
			memset(_source, '\0', _capacity);
			_source[_capacity] = '\0';
			memcpy(_source, buf, m_len);
		}
		memcpy(_source + pos + count2, _source + pos + count, m_len - pos - count);
		memcpy(_source + pos, cstr, count2);
		return *this;
	}
	template<class val_type>
	basic_string<val_type>& basic_string<val_type>::replace(size_type pos, size_type count, const val_type* cstr) {
		return replace(pos, count, cstr, strlen(cstr));
	}
	template<class val_type>
	basic_string<val_type>& basic_string<val_type>::replace(size_type pos, size_type count, size_type count2, val_type ch) {
		size_type m_len = length();
		if (pos >= m_len) {
			throw std::out_of_range("pos>=m_len越界");
			return *this;
		}
		if (pos + count > m_len)count = m_len - pos;
		if (count < count2 && m_len + count2 - count > _capacity) {
			while (m_len + count2 - count > _capacity)
				_capacity <<= 1;
			val_type* buf = new val_type[m_len];
			memcpy(buf, _source, m_len);
			delete[]_source;
			_source = new val_type[_capacity + 1];
			memset(_source, '\0', _capacity);
			_source[_capacity] = '\0';
			memcpy(_source, buf, m_len);
		}
		memcpy(_source + pos + count2, _source + pos + count, m_len - pos - count);
		memset(_source + pos, ch, count2);
		return *this;
	}
	template<class val_type>
	basic_string<val_type> basic_string<val_type>::substr(size_type pos, size_type count) const {
		size_type m_len = length();
		if (pos >= m_len) {
			throw std::out_of_range("pos>=this->length()");
			return {};
		}
		if (count == npos || pos + count > m_len)count = m_len - pos;
		basic_string<val_type> result(count, '\0');
		memcpy(result._source, _source + pos, count);
		return result;
	}
	template<class val_type>
	typename basic_string<val_type>::size_type basic_string<val_type>::copy(val_type* dest, size_type pos, size_type count) const {
		size_type m_len = length();
		if (pos >= m_len) {
			throw std::out_of_range("pos>=this->length()");
			return -1;
		}
		if (pos + count > m_len)count = m_len - pos;
		memcpy(dest, _source + pos, count);
		return count;
	}
	template<class val_type>
	void basic_string<val_type>::resize(size_type count, val_type ch) {
		size_type m_len = length();
		if (count > _capacity) {
			while (count > _capacity)
				_capacity <<= 1;
			val_type* buf = new val_type[m_len];
			memcpy(buf, _source, m_len);
			delete[] _source;
			_source = new val_type[_capacity + 1];
			delete[]buf;
			buf = nullptr;
		}
		memset(_source, '\0', _capacity);
		_source[_capacity] = '\0';
		memset(_source, ch, count);
	}
	template<class val_type>
	void basic_string<val_type>::swap(basic_string<val_type>& other) {
		size_type capbuf = _capacity;
		_capacity = other._capacity;
		other._capacity = capbuf;
		size_type m_len = this->length();
		size_type o_len = other.length();
		val_type* srcbuf = new val_type[m_len];
		memcpy(srcbuf, _source, m_len);
		delete[]_source;
		_source = new val_type[_capacity + 1];
		memset(_source, '\0', _capacity);
		_source[_capacity] = '\0';
		memcpy(_source, other._source, o_len);
		delete[]other._source;
		other._source = new val_type[other._capacity + 1];
		memset(other._source, '\0', other._capacity);
		other._source[other._capacity] = '\0';
		memcpy(other._source, srcbuf, m_len);
		delete[] srcbuf;
		srcbuf = nullptr;
	}
	//template<class val_type>
	//typename basic_string<val_type>::size_type basic_string<val_type>::find(const basic_string& str, size_type pos) const noexcept {
	//	//TODO
	//}
	//template<class val_type>
	//typename basic_string<val_type>::size_type basic_string<val_type>::find(const val_type* s, size_type pos, size_type count) const {
	//	//TODO
	//}
	//template<class val_type>
	//typename basic_string<val_type>::size_type basic_string<val_type>::find(const val_type* s, size_type pos) const {
	//	//TODO
	//}
	//template<class val_type>
	//typename basic_string<val_type>::size_type basic_string<val_type>::find(val_type ch, size_type pos) const noexcept {
	//	//TODO
	//}
	//template<class val_type>
	//typename basic_string<val_type>::size_type basic_string<val_type>::rfind(const basic_string& str, size_type pos) const noexcept {
	//	//TODO
	//}
	//template<class val_type>
	//typename basic_string<val_type>::size_type basic_string<val_type>::rfind(const val_type* s, size_type pos, size_type count) const {
	//	//TODO
	//}
	//template<class val_type>
	//typename basic_string<val_type>::size_type basic_string<val_type>::rfind(const val_type* s, size_type pos) const {
	//	//TODO
	//}
	//template<class val_type>
	//typename basic_string<val_type>::size_type basic_string<val_type>::rfind(val_type ch, size_type pos) const noexcept {
	//	//TODO
	//}
	//template<class val_type>
	//std::istream& basic_string<val_type>::operator>>(std::istream& in) {
	//	in >> _source;
	//	return in;
	//}
	template<class val_type>
	std::ostream& basic_string<val_type>::operator<<(std::ostream& out)
	{
		out << _source;
		return out;
	}
}

//定义
namespace std {
	template<class val_type>
	Mystd::basic_string<val_type> operator+(const Mystd::basic_string<val_type>& lhs, const Mystd::basic_string<val_type>& rhs) {
		return Mystd::basic_string<val_type>(lhs).append(rhs);
	}
	template<class val_type>
	Mystd::basic_string<val_type> operator+(const Mystd::basic_string<val_type>& lhs, const val_type* rhs) {
		return Mystd::basic_string<val_type>(lhs).append(rhs);
	}
	template<class val_type>
	Mystd::basic_string<val_type> operator+(const Mystd::basic_string<val_type>& lhs, const val_type rhs) {
		return Mystd::basic_string<val_type>(lhs).append(1, rhs);
	}
	template<class val_type>
	Mystd::basic_string<val_type> operator+(const val_type* lhs, const Mystd::basic_string<val_type>& rhs) {
		return Mystd::basic_string<val_type>(lhs).append(rhs);
	}
	template<class val_type>
	Mystd::basic_string<val_type> operator+(const val_type lhs, const Mystd::basic_string<val_type>& rhs) {
		return Mystd::basic_string<val_type>(lhs).append(rhs);
	}
	template< class val_type>
	void swap(std::basic_string<val_type>& lhs, std::basic_string<val_type>& rhs) {
		lhs.swap(rhs);
	}
	//template< class val_type>
	//istream& operator>>(istream& in, Mystd::basic_string<val_type>& str) {
	//	str.operator>>(in);
	//	return in;
	//}
	template< class val_type>
	ostream& operator<<(ostream& out, Mystd::basic_string<val_type>& str) {
		str.operator<<(out);
		return out;
	}
}
#endif

//#include<iostream>
//#include"string.h"
//
//int main() {
//
//	Mystd::string s1 = Mystd::string();
//	Mystd::string s2 = Mystd::string();
//	//构造方法测试
//	std::cout << "构造方法测试" << std::endl;
//	s1 = Mystd::string(10, '1');
//	std::cout << s1 << std::endl;	//1111111111
//	s1 = Mystd::string("123");
//	s2 = Mystd::string(s1);
//	std::cout << s2 << std::endl;	//123
//	s2 = Mystd::string(s1, 2, 1);
//	std::cout << s2 << std::endl;	//3
//	s2 = Mystd::string(s1, 1);
//	std::cout << s2 << std::endl;	//23
//	s2 = Mystd::string("123", 2);
//	std::cout << s2 << std::endl;	//12
//	//operator=
//	std::cout << "operator=" << std::endl;
//	s1 = "123";
//	std::cout << s1 << std::endl;	//123
//	s1 = 'a';
//	std::cout << s1 << std::endl;	//a
//	//at
//	std::cout << "at" << std::endl;
//	s1 = "12345";
//	std::cout << s1.at(0) << std::endl;	//1
//	std::cout << s1.at(1) << std::endl;	//2
//	std::cout << s1.at(2) << std::endl;	//3
//	//operator[]
//	std::cout << "operator[]" << std::endl;
//	s1 = "12345";
//	std::cout << s1[0] << std::endl;	//1
//	std::cout << s1[1] << std::endl;	//2
//	std::cout << s1[2] << std::endl;	//3
//	s1[0] = 'a';
//	s1[1] = 'b';
//	s1[2] = 'c';
//	std::cout << s1 << std::endl;		//abc45
//	//front
//	std::cout << "front" << std::endl;
//	s1 = "12345";
//	std::cout << s1.front() << std::endl;	//1
//	s1.front() = 'a';
//	std::cout << s1.front() << std::endl;	//a
//	//back
//	std::cout << "back" << std::endl;
//	s1 = "12345";
//	std::cout << s1.back() << std::endl;	//5
//	s1.back() = 'e';
//	std::cout << s1.back() << std::endl;	//e
//	//c_str
//	std::cout << "c_str" << std::endl;
//	s1 = "123";
//	std::cout << s1.c_str() << std::endl;	//123
//	//empty
//	std::cout << "empty" << std::endl;
//	s1 = "1234";
//	std::cout << s1.empty() << std::endl;	//0
//	s1 = "";
//	std::cout << s1.empty() << std::endl;	//1
//	//size|length
//	std::cout << "size|length" << std::endl;
//	s1 = { "123abc" };
//	std::cout << s1.size() << std::endl;	//6
//	std::cout << s1.length() << std::endl;	//6
//	s1[3] = '\0';
//	std::cout << s1.size() << std::endl;	//3
//	std::cout << s1.length() << std::endl;	//3
//	s1[0] = '\0';
//	std::cout << s1.size() << std::endl;	//0
//	std::cout << s1.length() << std::endl;	//0
//	//capacity
//	std::cout << "capacity" << std::endl;
//	s1 = "123";
//	std::cout << s1.capacity() << std::endl;	//3
//	s1 += "111111111111111111111111111";
//	std::cout << s1.capacity() << std::endl;	//48
//	//reserve
//	std::cout << "reserve" << std::endl;
//	s1 = "123";
//	std::cout << s1.capacity() << std::endl;	//3
//	s1.reserve(100);
//	std::cout << s1.capacity() << std::endl;	//100
//	s1.reserve(1);
//	std::cout << s1.capacity() << std::endl;	//3
//	s1.reserve(5);
//	std::cout << s1.capacity() << std::endl;	//5
//	//shrink_to_fit
//	std::cout << "shrink_to_fit" << std::endl;
//	s1 = "123";
//	std::cout << s1.capacity() << std::endl;	//3
//	s1.reserve(100);
//	std::cout << s1.capacity() << std::endl;	//100
//	s1.shrink_to_fit();
//	std::cout << s1.capacity() << std::endl;	//3
//	//clear
//	std::cout << "clear" << std::endl;
//	s1 = "123";
//	std::cout << s1 << std::endl;				//123
//	s1.clear();
//	std::cout << s1 << std::endl;				//
//	std::cout << s1.size() << std::endl;		//0
//	std::cout << s1.capacity() << std::endl;	//3
//	//insert
//	std::cout << "insert" << std::endl;
//	s1 = "123";
//	std::cout << s1 << std::endl;				//123
//	s1.insert(0, 5, 'a');
//	std::cout << s1 << std::endl;				//aaaaa123
//	s1.insert(3, "123");
//	std::cout << s1 << std::endl;				//aaa123aa123
//	s1.insert(3, "abc\0abc", 5);
//	std::cout << s1 << std::endl;				//aaaabc\0a123aa123
//	s1[6] = 'e';
//	std::cout << s1 << std::endl;				//aaaabcea123aa123
//	s1 = "123";
//	s2 = "456";
//	s1.insert(1, s2, 1);
//	std::cout << s1 << std::endl;				//14523
//	//erase
//	std::cout << "erase" << std::endl;
//	s1 = "123456789";
//	std::cout << s1 << std::endl;				//123456789
//	s1.erase(2, 5);
//	std::cout << s1 << std::endl;				//1289
//	s1.erase(2);
//	std::cout << s1 << std::endl;				//129
//	//push_back
//	std::cout << "push_back" << std::endl;
//	s1 = "123456";
//	std::cout << s1 << std::endl;				//123456
//	s1.push_back('a');
//	std::cout << s1 << std::endl;				//123456a
//	s1.push_back('b');
//	std::cout << s1 << std::endl;				//123456ab
//	s1.push_back('c');
//	std::cout << s1 << std::endl;				//123456abc
//	//pop_back
//	std::cout << "pop_back" << std::endl;
//	s1 = "123456";
//	std::cout << s1 << std::endl;				//123456
//	s1.pop_back();
//	std::cout << s1 << std::endl;				//12345
//	s1.pop_back();
//	std::cout << s1 << std::endl;				//1234
//	s1.pop_back();
//	std::cout << s1 << std::endl;				//123
//	//append
//	std::cout << "append" << std::endl;
//	s1 = "1";
//	std::cout << s1 << std::endl;				//1
//	s1.append(5, 'a');
//	std::cout << s1 << std::endl;				//1aaaaa
//	s2 = "321";
//	s1.append(s2);
//	std::cout << s1 << std::endl;				//1aaaaa321
//	s1.append("1\0ba", 3);
//	std::cout << s1 << std::endl;				//1aaaaa3211
//	s1[10] = 'c';
//	std::cout << s1 << std::endl;				//1aaaaa3211cb
//	s1.append("123");
//	std::cout << s1 << std::endl;				//1aaaaa3211cb123
//	//operator+=
//	std::cout << "operator+=" << std::endl;
//	s1 = "123";
//	std::cout << s1 << std::endl;				//123
//	s2 = "456";
//	std::cout << s2 << std::endl;				//456
//	s1 += s2;
//	std::cout << s1 << std::endl;				//123456
//	s2 += s2;
//	std::cout << s2 << std::endl;				//456456
//	s1 += "abc";
//	std::cout << s1 << std::endl;				//123456abc
//	s1 += '#';
//	std::cout << s1 << std::endl;				//123456abc#
//	//compare
//	std::cout << "compare" << std::endl;
//	s1 = "123";
//	s2 = "012";
//	std::cout << s1.compare(s2) << std::endl;	//1
//	s1 = "123";
//	s2 = "1234";
//	std::cout << s1.compare(s2) << std::endl;	//-1
//	s1 = "123";
//	s2 = "123";
//	std::cout << s1.compare(s2) << std::endl;	//0
//	s1 = "3123";
//	s2 = "123";
//	std::cout << s1.compare(1, 3, s2) << std::endl;	//0
//	s1 = "3123";
//	s2 = "321123";
//	std::cout << s1.compare(1, 3, s2, 3, 3) << std::endl;	//0
//	s1 = "123";
//	std::cout << s1.compare("321") << std::endl;	//-1
//	s1 = "3123";
//	std::cout << s1.compare(1, 3, "123") << std::endl;	//0
//	s1 = "3123";
//	std::cout << s1.compare(1, 3, "123\0a", 4) << std::endl;	//-1
//	//replace
//	std::cout << "replace" << std::endl;
//	s1 = "123";
//	s2 = "456";
//	s1.replace(1, 1, s2);
//	std::cout << s1 << std::endl;	//14563
//	s1 = "123";
//	s2 = "456";
//	s1.replace(1, 1, s2, 1, 2);
//	std::cout << s1 << std::endl;	//1563
//	s1 = "123";
//	s1.replace(1, 1, "456", 2);
//	std::cout << s1 << std::endl;	//1453
//	s1 = "123";
//	s1.replace(1, 1, "45\0ab", 5);
//	std::cout << s1 << std::endl;	//145
//	s1[3] = 'e';
//	std::cout << s1 << std::endl;	//145eab3
//	s1 = "123";
//	s1.replace(1, 1, "45ab");
//	std::cout << s1 << std::endl;	//145ab3
//	s1 = "123";
//	s1.replace(1, 1, 5, 'a');
//	std::cout << s1 << std::endl;	//1aaaaa3
//	//substr
//	std::cout << "substr" << std::endl;
//	s1 = "123456789";
//	s2 = s1.substr(1, 2);
//	std::cout << s2 << std::endl;	//23
//	s2 = s1.substr(3);
//	std::cout << s2 << std::endl;	//456789
//	//copy
//	std::cout << "copy" << std::endl;
//	s1 = "123456789";
//	char buf[4] = { '\0' };
//	s1.copy(buf, 0, 3);
//	std::cout << buf << std::endl;	//123
//	s1.copy(buf, 3, 3);
//	std::cout << buf << std::endl;	//456
//	//resize
//	std::cout << "resize" << std::endl;
//	s1 = "123";
//	s1.resize(10, '1');
//	std::cout << s1 << std::endl;				//1111111111
//	std::cout << s1.size() << std::endl;		//10
//	std::cout << s1.capacity() << std::endl;	//12
//	s1.resize(5, 'a');
//	std::cout << s1 << std::endl;				//aaaaa
//	std::cout << s1.size() << std::endl;		//5
//	std::cout << s1.capacity() << std::endl;	//12
//	//swap
//	std::cout << "swap" << std::endl;
//	s1 = "123";
//	s2 = "456";
//	s1.swap(s2);
//	std::cout << s1 << std::endl;	//456
//	std::cout << s2 << std::endl;	//123
//	s1 = "123";
//	s2 = "";
//	s1.swap(s2);
//	std::cout << s1 << std::endl;	//
//	std::cout << s2 << std::endl;	//123
//	s1 = "123";
//	s2 = "4567";
//	s1.swap(s2);
//	std::cout << s1 << std::endl;	//4567
//	std::cout << s2 << std::endl;	//123
//	s1 = "";
//	s2 = "";
//	s1.swap(s2);
//	std::cout << s1 << std::endl;	//
//	std::cout << s2 << std::endl;	//
//
//	std::swap(s1, s2);
//	//operator<<  operator>>
//	//std::cout << "operator<<  operator>>" << std::endl;
//	//std::cout << "请输入s1 : ";
//	//std::cin >> s1;
//	//std::cout << "s1 : " << s1 << std::endl;
//}