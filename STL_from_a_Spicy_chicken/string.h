#ifndef _MYSTRING_H
#define _MYSTRING_H

#include<stdexcept>
//����
namespace Mystd {
	template<class val_type>
	class basic_string {
		using size_type = size_t;
	private:
		val_type* _source;
		size_type _capacity;
	public:
		//Ĭ�Ϲ��캯��������� string ��ӵ�����С��17��������
		basic_string();
		//����ӵ���ַ� ch �� count �������� string 
		basic_string(size_type count, val_type ch = '\0');
		//���ƹ��캯��.��other���Ӵ�[pos, pos+count)����string.��count==npos��δָ��count,����������Ӵ�Խ���ַ����Ľ�β,��������Ӵ�Ϊ[pos,other.size())
		basic_string(const basic_string& other, size_type pos = 0, size_type count = npos);
		//��s��ָ����ַ�������count���ַ�����string s�ܰ������ַ�.��count����s����,��������ִ�Ϊԭ�ַ���s
		basic_string(const val_type* s, size_type count = npos);
		//�ƶ����캯��.���ƶ����幹��ӵ��other���ݵ�string
		basic_string(basic_string&& other)noexcept;
		//��������
		~basic_string();
		//��str�ĸ����滻����
		basic_string& operator=(const basic_string& str);
		//���ƶ�������str�������滻����
		basic_string& operator=(basic_string&& str)noexcept;
		//��s��ָ��Ŀ���ֹ�ַ����������滻����
		basic_string& operator=(const val_type* s);
		//���ַ�ch�������滻����
		basic_string& operator=(val_type ch);
		//���ص�λ��ָ��λ��pos���ַ�������.���б߽���,�Ƿ�����ʱ�׳�std::out_of_range���͵��쳣
		val_type& at(size_type pos);
		const val_type& at(size_type pos) const;
		//��pos<size()ʱ���ص�λ��ָ��λ��pos���ַ�������,�����б߽���
		val_type& operator[](size_type pos);
		const val_type& operator[](size_type pos) const;
		//���ص�string�����ַ�������.��empty()==true����Ϊδ����
		val_type& front();
		const val_type& front() const;
		//���ص�string��ĩ�ַ�������.��empty()==true����Ϊδ����
		val_type& back();
		const val_type& back() const;
		//����ָ��ӵ�����ݵȼ��ڴ洢���ַ����еĿ���ֹ�ַ������ָ��
		const val_type* c_str() const noexcept;
		//��� string �Ƿ����ַ�
		bool empty() const noexcept;
		//����string�е�val_typeԪ����
		size_type size() const noexcept;
		size_type length() const noexcept;
		//���ص�ǰ��Ϊ�ַ�������ռ���ַ���
		size_type capacity() const noexcept;
		//����basic_string�����С���мƻ�����,ʹ������׼ȷ�ع���洢����
		//��new_cap���ڵ�ǰcapacity(),������´洢,����capacity()���ڻ����new_cap
		//��new_capС�ڵ�ǰcapacity(),�����Ƿ�ǿ�Ƶ���������
		//��new_capС�ڵ�ǰsize(),�����Ƿ�ǿ�Ƶ��������ʺ�(shrink-to-fit)����,�ȼ���shrink_to_fit()
		void reserve(size_type new_cap = 0);
		//�����Ƴ�δʹ�õ�����,����capacity()��size() 
		void shrink_to_fit();
		//��string�Ƴ������ַ�
		void clear() noexcept;
		//��λ��index����count���ַ�ch�ĸ���
		basic_string& insert(size_type index, size_type count, val_type ch);
		//��λ��index����s��ָ��Ŀ���ֹ�ַ���
		basic_string& insert(size_type index, const val_type* s);
		//��λ��index���뷶Χ[s,s+count)�е��ַ�,��Χ�ܺ��п��ַ�
		basic_string& insert(size_type index, const val_type* s, size_type count);
		//��λ��index������str.substr(index_str,count)��õ��ַ���
		basic_string& insert(size_type index, const basic_string& str, size_type index_str = 0, size_type count = npos);
		//�Ƴ���index��ʼ��std::min(count,size()-index)���ַ�
		basic_string& erase(size_type index = 0, size_type count = 1);
		//�󸽸����ַ�ch���ַ���β
		void push_back(val_type ch);
		//���ַ����Ƴ�ĩ�ַ�
		void pop_back();
		//��count��ch�ĸ���
		basic_string& append(size_type count, val_type ch);
		//��str���Ӵ�[pos,pos+count).��������Ӵ�Խ��string��β,����count==npos,��󸽵��Ӵ�Ϊ[pos,size()).��pos>str.size(),���׳�std::out_of_range
		basic_string& append(const basic_string& str, size_type pos = 0, size_type count = npos);
		//�󸽷�Χ[s,s+count)�е��ַ�.�˷�Χ�ܺ��п��ַ�
		basic_string& append(const val_type* s, size_type count);
		//��s��ָ��Ŀ���ֹ�ַ���
		basic_string& append(const val_type* s);
		//��string str
		basic_string& operator+=(const basic_string& str);
		//���ַ�ch 
		basic_string& operator+=(val_type ch);
		//��s��ָ��Ŀ���ֹ�ַ���
		basic_string& operator+=(const val_type* s);
		//�Ƚϴ��ַ�����str
		int compare(const basic_string& str) const noexcept;
		//�Ƚϴ��ַ�����[pos1,pos1+count1)�Ӵ���str.���count1>size()-pos1,��ô�Ӵ���[pos1,size()) 
		int compare(size_type pos1, size_type count1, const basic_string& str) const;
		//�Ƚϴ��ַ�����[pos1,pos1+count1)�Ӵ���str���Ӵ�[pos2,pos2+count2).���count1>size()-pos1,��ô��һ�Ӵ���[pos1,size()).���count2>str.size()-pos2,��ô�ڶ��Ӵ���[pos2,str.size())
		int compare(size_type pos1, size_type count1, const basic_string& str, size_type pos2, size_type count2 = npos) const;
		//�Ƚϴ��ַ�����ʼ�� s ��ָ��Ŀ���ֹ�ַ�����
		int compare(const val_type* s) const;
		//�Ƚϴ��ַ�����[pos1,pos1+count1)�Ӵ���ʼ��s��ָ��Ŀ���ֹ�ַ�����.���count1>size()-pos1,��ô�Ӵ���[pos1,size())
		int compare(size_type pos1, size_type count1, const val_type* s) const;
		//�Ƚϴ��ַ�����[pos1,pos1+count1)�Ӵ��뷶Χ[s,s+count2)�е��ַ�.(ע��:��Χ[s,s+count2)�е��ַ��ɰ������ַ�)
		int compare(size_type pos1, size_type count1, const val_type* s, size_type count2) const;
		//��string str�滻[pos, pos + count)��ָʾ��string����
		basic_string& replace(size_type pos, size_type count, const basic_string& str);
		//��str���Ӵ�[pos2,pos2+count2)�滻[pos,pos+count)��ָʾ��string����
		basic_string& replace(size_type pos, size_type count, const basic_string& str, size_type pos2, size_type count2 = npos);
		//�Է�Χ[cstr,cstr+count2)�е��ַ��滻[pos,pos+count)��ָʾ��string����
		basic_string& replace(size_type pos, size_type count, const val_type* cstr, size_type count2);
		//�Է�Χ[cstr,cstr+length(cstr))�е��ַ��滻[pos,pos+count)��ָʾ��string����
		basic_string& replace(size_type pos, size_type count, const val_type* cstr);
		//���ַ�ch��count2�������滻[pos,pos+count)��ָʾ��string����
		basic_string& replace(size_type pos, size_type count, size_type count2, val_type ch);
		//�����Ӵ�[pos,pos+count).��������ִ�Խ���ַ����Ľ�β,��count����size()-pos(������count==npos),�򷵻ص��Ӵ�Ϊ[pos, size())
		basic_string substr(size_type pos = 0, size_type count = npos) const;
		//�����Ӵ� [pos,pos+count)��dest��ָ����ַ���.��������Ӵ�Խ��string��β,����count==npos,���Ƶ��Ӵ�Ϊ[pos,size()).�������ַ������ǿ���ֹ��.��pos>size(),���׳�std::out_of_range
		size_type copy(val_type* dest, size_type pos, size_type count) const;
		//����string��С�Ժ�count���ַ�.����ǰ��СС��count,��󸽶�����ַ�.����ǰ��С����count,������string��Ϊ����count��Ԫ��
		void resize(size_type count, val_type ch = '\0');
		//����string��other������
		void swap(basic_string& other);
		////Ѱ�ҵ��� str ���׸��Ӵ�.����ʼ��pos,���ҵ����Ӵ����벻ʼ��pos֮ǰ��λ��
		//size_type find(const basic_string& str, size_type pos = 0) const noexcept;
		////Ѱ�ҵ��ڷ�Χ[s,s+count)���׸��Ӵ�.�˷�Χ�ܺ����ַ�.����ʼ��pos,���ҵ����Ӵ����벻ʼ��pos֮ǰ��λ��
		//size_type find(const val_type* s, size_type pos, size_type count) const;
		////Ѱ�ҵ���s��ָ����ַ������׸��Ӵ�.���׸����ַ�ȷ���ַ�������.����ʼ��pos,���ҵ����Ӵ����벻ʼ��pos֮ǰ��λ��
		//size_type find(const val_type* s, size_type pos = 0) const;
		////Ѱ���׸��ַ�ch.����ʼ��pos,���ҵ����Ӵ����벻ʼ��pos֮ǰ��λ��
		//size_type find(val_type ch, size_type pos = 0) const noexcept;
		////Ѱ�ҵ���str������Ӵ�.����ʼ��pos,���ҵ����Ӵ����벻ʼ��pos���λ��.����npos���κβ�С��size()-1��ֵ��Ϊpos����,���������ַ���������
		//size_type rfind(const basic_string& str, size_type pos = npos) const noexcept;
		////Ѱ�ҵ��ڷ�Χ[s,s+count)������Ӵ�.�˷�Χ�ܰ������ַ�.����ʼ��pos,���ҵ����Ӵ����벻ʼ��pos���λ��.����npos���κβ�С��size()-1��ֵ��Ϊpos����,���������ַ���������
		//size_type rfind(const val_type* s, size_type pos, size_type count) const;
		////Ѱ�ҵ���s��ָ����ַ���������Ӵ�.���׸����ַ�ȷ���ַ������ȡ�.����ʼ��pos,���ҵ����Ӵ����벻ʼ��pos���λ��.����npos���κβ�С��size()-1��ֵ��Ϊpos����,���������ַ���������
		//size_type rfind(const val_type* s, size_type pos = npos) const;
		////Ѱ�ҵ���ch������ַ�.����ʼ��pos,���ҵ����Ӵ����벻ʼ��pos���λ��.����npos���κβ�С��size()-1��ֵ��Ϊpos����,���������ַ���������
		//size_type rfind(val_type ch, size_type pos = npos) const noexcept;
		////��׼��������
		//std::istream& operator>>(std::istream& in);
		//��׼�������
		std::ostream& operator<<(std::ostream& out);
		//��������ֵ,����size_type���Ϳɱ�ʾ�����ֵ.׼ȷ�����������ﾳ,��ͨ��,�ڴ�string�±�ĺ�����֮Ϊ�ַ���βָʾ��,����string�±�ĺ�����֮Ϊ����ָʾ��
		static const size_type npos = -1;
	};

	using string = basic_string<char>;
	using wstring = basic_string<wchar_t>;
}

//����
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

//����
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
			throw std::out_of_range("posλ�ô��ڵ���other����");
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
			throw std::out_of_range("pos>=length()Խ��");
			return _source[0];
		}
		return _source[pos];
	}
	template<class val_type>
	const val_type& basic_string<val_type>::at(size_type pos) const {
		if (pos >= length()) {
			throw std::out_of_range("pos>=length()Խ��");
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
			throw std::out_of_range("index>=length()Խ��");
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
			throw std::out_of_range("size == 0Խ��");
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
			throw std::out_of_range("pos>=str.length()Խ��");
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
			throw std::out_of_range("pos1>=this->length()Խ��");
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
			throw std::out_of_range("pos1>=this->length()Խ��");
			return -2;
		}
		size_type s_len = str.length();
		if (pos2 >= s_len) {
			throw std::out_of_range("pos2>=str->length()Խ��");
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
			throw std::out_of_range("pos1>=this->length()Խ��");
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
			throw std::out_of_range("pos1>=this->length()Խ��");
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
			throw std::out_of_range("pos>=m_lenԽ��");
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
			throw std::out_of_range("pos>=m_lenԽ��");
			return *this;
		}
		size_type s_len = str.length();
		if (pos2 >= s_len) {
			throw std::out_of_range("pos2>=s_lenԽ��");
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
			throw std::out_of_range("pos>=m_lenԽ��");
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
			throw std::out_of_range("pos>=m_lenԽ��");
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

//����
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
//	//���췽������
//	std::cout << "���췽������" << std::endl;
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
//	//std::cout << "������s1 : ";
//	//std::cin >> s1;
//	//std::cout << "s1 : " << s1 << std::endl;
//}