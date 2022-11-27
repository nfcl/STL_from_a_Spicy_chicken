#ifndef _MY_VECTOR_
#define _MY_VECTOR_

#include<initializer_list>  //列表初始化
#include<stdexcept>         //标准异常
#include<memory>

namespace Mystd {

    template<class _Ty, class _Alloc = std::allocator<_Ty>>
    class vector {
    public:
        using val_type = _Ty;
        using size_type = size_t;
        using Allocator = _Alloc;
        using this_type = vector<_Ty>;
        using iterator = _Ty*;
        using const_iterator = const _Ty*;
        using pointer = _Ty*;
        using const_pointer = const _Ty*;
        using reference = _Ty&;
        using const_reference = const _Ty&;
    private:
        Allocator _alloc;
        iterator _start;
        iterator _end;
        iterator _end_of_storage;
    public:
        vector();
        vector(size_type count, const_reference value = val_type());
        //template<class InputIt>
        //vector(InputIt first, InputIt last, const Allocator& alloc = Allocator());
        vector(const this_type& other);
        vector(this_type&& other)noexcept;
        vector(std::initializer_list<val_type> init);
        ~vector();
        this_type& operator=(const this_type& other);
        this_type& operator=(this_type&& other)noexcept;
        this_type& operator=(std::initializer_list<val_type> ilist);
        reference at(size_type pos);
        const_reference at(size_type pos) const;
        reference operator[](size_type pos);
        const_reference operator[](size_type pos)const;
        reference front();
        const_reference front() const;
        reference back();
        const_reference back() const;
        pointer data() noexcept;
        const_pointer data() const noexcept;
        iterator begin() noexcept;
        const_iterator begin() const noexcept;
        const_iterator cbegin() const noexcept;
        iterator end() noexcept;
        const_iterator end() const noexcept;
        const_iterator cend() const noexcept;
        bool empty() const noexcept;
        size_type size() const noexcept;
        //size_type max_size() const noexcept;
        void reserve(size_type new_cap);
        size_type capacity() const noexcept;
        void shrink_to_fit();
        void clear() noexcept;
        iterator insert(const_iterator pos, const_reference value);
        iterator insert(const_iterator pos, val_type&& value);
        iterator insert(const_iterator pos, size_type count, const_reference value);
        //template< class InputIt >
        //iterator insert(const_iterator pos, InputIt first, InputIt last);
        iterator insert(const_iterator pos, std::initializer_list<val_type> ilist);
        template<class... Args>
        iterator emplace(const_iterator pos, Args&&... args);
        iterator erase(const_iterator pos);
        iterator erase(const_iterator first, const_iterator last);
        void push_back(const reference value);
        void push_back(val_type&& value);
        template<class... Args>
        void emplace_back(Args&&... args);
        void pop_back();
        void resize(size_type count);
        void resize(size_type count, const_reference value);
        void swap(this_type& other);
    };
}

namespace std {
    template<class _Ty, class _Alloc>
    void swap(Mystd::vector<_Ty, _Alloc>& lhs, Mystd::vector<_Ty, _Alloc>& rhs);
    template<class _Ty, class _Alloc>
    bool operator==(const Mystd::vector<_Ty, _Alloc>& lhs, const Mystd::vector<_Ty, _Alloc>& rhs);
    template<class _Ty, class _Alloc>
    bool operator!=(const Mystd::vector<_Ty, _Alloc>& lhs, const Mystd::vector<_Ty, _Alloc>& rhs);
    template<class _Ty, class _Alloc>
    bool operator<(const Mystd::vector<_Ty, _Alloc>& lhs, const Mystd::vector<_Ty, _Alloc>& rhs);
    template<class _Ty, class _Alloc>
    bool operator<=(const Mystd::vector<_Ty, _Alloc>& lhs, const Mystd::vector<_Ty, _Alloc>& rhs);
    template<class _Ty, class _Alloc>
    bool operator>(const Mystd::vector<_Ty, _Alloc>& lhs, const Mystd::vector<_Ty, _Alloc>& rhs);
    template<class _Ty, class _Alloc>
    bool operator>=(const Mystd::vector<_Ty, _Alloc>& lhs, const Mystd::vector<_Ty, _Alloc>& rhs);
}

namespace Mystd {
    template<class _Ty, class _Alloc>
    vector<_Ty, _Alloc>::vector()
    {
        _start = _alloc.allocate(0);
        _end = _end_of_storage = _start;
    }
    template<class _Ty, class _Alloc>
    vector<_Ty, _Alloc>::vector(size_type count, const_reference value)
    {
        _start = _alloc.allocate(count);
        std::uninitialized_fill(_start, _start + count, value);
        _end = _end_of_storage = _start + count;
    }
    //template<class _Ty, class _Alloc>
    //template<class InputIt>
    //vector<_Ty, _Alloc>::vector(InputIt first, InputIt last, const Allocator& alloc)
    //{
    //    size_type n = last - first;
    //    _alloc = alloc;
    //    _start = _alloc.allocate(n);
    //    _end = _end_of_storage = std::uninitialized_copy(first, last, _start);
    //}
    template<class _Ty, class _Alloc>
    vector<_Ty, _Alloc>::vector(const this_type& other)
    {
        size_type n = other.cend() - other.cbegin();
        _start = _alloc.allocate(n);
        _end = _end_of_storage = std::uninitialized_copy(other.cbegin(), other.cend(), _start);
    }
    template<class _Ty, class _Alloc>
    vector<_Ty, _Alloc>::vector(this_type&& other)noexcept
    {
        _alloc = std::move(other._alloc);
        _start = other._start;
        _end = other._end;
        _end_of_storage = other._end_of_storage;
        other._start = other._end = other._end_of_storage = other._alloc.allocate(0);
    }
    template<class _Ty, class _Alloc>
    vector<_Ty, _Alloc>::vector(std::initializer_list<val_type> init)
    {
        size_type n = init.size();
        _start = _alloc.allocate(n);
        _end = _end_of_storage = std::uninitialized_copy(init.begin(), init.end(), _start);
    }
    template<class _Ty, class _Alloc>
    vector<_Ty, _Alloc>::~vector()
    {
        if (_start)
        {
            while (_end != _start)
                _alloc.destroy(--_end);
        }
        _alloc.deallocate(_start, capacity());
        _start = _end_of_storage = _end = nullptr;
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::this_type& vector<_Ty, _Alloc>::operator=(const this_type& other)
    {
        _alloc.deallocate(_start, size());
        _start = _alloc.allocate(other.size());
        _end = _end_of_storage = std::uninitialized_copy(other._start, other._end, _start);
        return *this;
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::this_type& vector<_Ty, _Alloc>::operator=(this_type&& other)noexcept
    {
        _alloc.deallocate(_start, size());
        _start = _alloc.allocate(other.size());
        _end = _end_of_storage = std::uninitialized_copy(other._start, other._end, _start);
        return *this;
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::this_type& vector<_Ty, _Alloc>::operator=(std::initializer_list<val_type> ilist)
    {
        _alloc.deallocate(_start, size());
        size_type n = ilist.size();
        _start = _alloc.allocate(n);
        _end = _end_of_storage = std::uninitialized_copy(ilist.begin(), ilist.end(), _start);
        return *this;
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::reference vector<_Ty, _Alloc>::at(size_type pos)
    {
        return _start[pos];
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::const_reference vector<_Ty, _Alloc>::at(size_type pos) const
    {
        return _start[pos];
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::reference vector<_Ty, _Alloc>::operator[](size_type pos)
    {
        return _start[pos];
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::const_reference vector<_Ty, _Alloc>::operator[](size_type pos) const
    {
        return _start[pos];
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::reference vector<_Ty, _Alloc>::front()
    {
        return _start[0];
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::const_reference vector<_Ty, _Alloc>::front() const
    {
        return _start[0];
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::reference vector<_Ty, _Alloc>::back()
    {
        return *(_end - 1);
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::const_reference vector<_Ty, _Alloc>::back() const
    {
        return *(_end - 1);
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::pointer vector<_Ty, _Alloc>::data() noexcept
    {
        return _start;
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::const_pointer vector<_Ty, _Alloc>::data() const noexcept
    {
        return _start;
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::iterator vector<_Ty, _Alloc>::begin() noexcept
    {
        return _start;
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::const_iterator vector<_Ty, _Alloc>::begin() const noexcept
    {
        return _start;
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::const_iterator vector<_Ty, _Alloc>::cbegin() const noexcept
    {
        return _start;
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::iterator vector<_Ty, _Alloc>::end() noexcept
    {
        return _end;
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::const_iterator vector<_Ty, _Alloc>::end() const noexcept
    {
        return _end;
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::const_iterator vector<_Ty, _Alloc>::cend() const noexcept
    {
        return _end;
    }
    template<class _Ty, class _Alloc>
    bool vector<_Ty, _Alloc>::empty() const noexcept
    {
        return _start == _end;
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::size_type vector<_Ty, _Alloc>::size() const noexcept
    {
        return _end - _start;
    }
    //template<class _Ty, class _Alloc>
    //typename vector<_Ty, _Alloc>::size_type vector<_Ty, _Alloc>::max_size() const noexcept {
    //
    //}
    template<class _Ty, class _Alloc>
    void vector<_Ty, _Alloc>::reserve(size_type new_cap) {

        size_type old_cap = capacity();

        if (old_cap < new_cap) {
            size_type _size = size();
            Allocator buf = std::allocator<val_type>();
            iterator _new_start = buf.allocate(new_cap);
            std::uninitialized_copy(_start, _end, _new_start);
            _alloc.deallocate(_start, old_cap);
            _alloc = buf;
            _start = _new_start;
            _end = _start + _size;
            _end_of_storage = _start + new_cap;
        }
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::size_type vector<_Ty, _Alloc>::capacity() const noexcept {
        return _end_of_storage - _start;
    }
    template<class _Ty, class _Alloc>
    void vector<_Ty, _Alloc>::shrink_to_fit() {
        size_type _size = size();
        size_type old_cap = capacity();

        if (_size != old_cap) {
            Allocator buf = std::allocator<val_type>();
            iterator _new_start = buf.allocate(_size);
            std::uninitialized_copy(_start, _end, _new_start);
            _alloc.deallocate(_start, old_cap);
            _start = _alloc.allocate(_size);
            _end = _end_of_storage = std::uninitialized_copy(_new_start, _new_start + _size, _start);
        }
    }
    template<class _Ty, class _Alloc>
    void vector<_Ty, _Alloc>::clear() noexcept {
        while (_end != _start) {
            --_end;
            _alloc.destroy(_end);
        }
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::iterator vector<_Ty, _Alloc>::insert(const_iterator pos, const_reference value) {
        return emplace(pos, value);
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::iterator vector<_Ty, _Alloc>::insert(const_iterator pos, val_type&& value) {
        return emplace(pos, std::move(value));
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::iterator vector<_Ty, _Alloc>::insert(const_iterator pos, size_type count, const_reference value) {
        if (pos<_start || pos>_end)throw std::out_of_range("insert 插入位置非法");
        size_type _where = pos - _start;
        if (_end + count > _end_of_storage) {
            size_type _size = size();
            size_type old_cap = capacity();
            size_type new_cap = old_cap << 1;
            while (_size + count > new_cap) {
                new_cap <<= 1;
            }
            Allocator buf = std::allocator<val_type>();
            iterator _new_start = buf.allocate(_size);
            iterator _new_end = std::uninitialized_copy(_start, _end, _new_start);
            _alloc.deallocate(_start, old_cap);
            _start = _alloc.allocate(new_cap);
            _end_of_storage = _start + new_cap;
            _end = _start + _size + count;
            std::uninitialized_copy(_new_start, _new_start + _where, _start);
            std::uninitialized_copy(_new_start + _where, _new_end, _start + _where + count);
            std::uninitialized_fill(_start + _where, _start + _where + count, value);
        }
        else if (pos == _end) {
            std::uninitialized_fill(_end, _end + count, value);
            _end += count;
        }
        else {
            for (iterator dest = _end + count, src = _end; dest != pos + count - 1; --dest, --src) {
                *dest = std::move(*src);
            }
            std::uninitialized_fill(pos, pos + count, value);
            _end += count;
        }
        return _start + _where;
    }
    //template<class _Ty, class _Alloc>
    //template< class InputIt >
    //typename vector<_Ty, _Alloc>::iterator vector<_Ty, _Alloc>::insert(const_iterator pos, InputIt first, InputIt last){
    //
    //}
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::iterator vector<_Ty, _Alloc>::insert(const_iterator pos, std::initializer_list<val_type> ilist) {
        if (pos<_start || pos>_end)throw std::out_of_range("insert 插入位置非法");
        size_type _where = pos - _start;
        size_type count = ilist.size();
        if (_end + count > _end_of_storage) {
            size_type _size = size();
            size_type old_cap = capacity();
            size_type new_cap = old_cap << 1;
            while (_size + count > new_cap) {
                new_cap <<= 1;
            }
            Allocator buf = std::allocator<val_type>();
            iterator _new_start = buf.allocate(_size);
            iterator _new_end = std::uninitialized_copy(_start, _end, _new_start);
            _alloc.deallocate(_start, old_cap);
            _start = _alloc.allocate(new_cap);
            _end_of_storage = _start + new_cap;
            _end = _start + _size + count;
            std::uninitialized_copy(_new_start, _new_start + _where, _start);
            std::uninitialized_copy(_new_start + _where, _new_end, _start + _where + count);
            std::uninitialized_copy(ilist.begin(), ilist.end(), _start + _where);
        }
        else if (pos == _end) {
            std::uninitialized_copy(ilist.begin(), ilist.end(), _end);
            _end += count;
        }
        else {
            for (iterator dest = _end + count, src = _end; dest != pos + count - 1; --dest, --src) {
                *dest = std::move(*src);
            }
            std::uninitialized_copy(ilist.begin(), ilist.end(), _start + _where);
            _end += count;
        }
        return _start + _where;
    }
    template<class _Ty, class _Alloc>
    template<class... Args>
    typename vector<_Ty, _Alloc>::iterator vector<_Ty, _Alloc>::emplace(const_iterator pos, Args&&... args) {
        if (pos < _start || pos> _end)throw std::out_of_range("emplace 插入位置非法");
        size_type _where = pos - _start;
        if (_end == _end_of_storage) {
            size_type old_cap = capacity();
            size_type new_cap = old_cap == 0 ? 1 : old_cap << 1;
            Allocator buf = std::allocator<val_type>();
            iterator _new_start = buf.allocate(old_cap + 1);
            std::uninitialized_copy(_start, _start + _where, _new_start);
            buf.construct(_new_start + _where, std::forward<Args>(args)...);
            iterator _new_end = std::uninitialized_copy(_start + _where, _end, _new_start + _where + 1);
            _alloc.deallocate(_start, old_cap);
            _start = _alloc.allocate(new_cap);
            std::uninitialized_copy(_new_start, _new_end, _start);
            _end = _start + old_cap + 1;
            _end_of_storage = _start + new_cap;
        }
        else if (pos == _end) {
            _alloc.construct(_end, std::forward<Args>(args)...);
            ++_end;
        }
        else {
            for (iterator dest = _end, src = _end - 1; dest != pos; --dest, --src) {
                *dest = std::move(*src);
            }
            _alloc.construct(pos, std::forward<Args>(args)...);
            ++_end;
        }
        return _start + _where;
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::iterator vector<_Ty, _Alloc>::erase(const_iterator pos) {
        if (pos < _start || pos >= _end)throw std::out_of_range("erase 删除位置非法");
        size_type _where = pos - _start;
        for (iterator dest = _start + _where, src = dest + 1; src != _end; ++dest, ++src) {
            *dest = std::move(*src);
        }
        --_end;
        _alloc.destroy(_end);
        return _start + _where;
    }
    template<class _Ty, class _Alloc>
    typename vector<_Ty, _Alloc>::iterator vector<_Ty, _Alloc>::erase(const_iterator first, const_iterator last) {
        if (first<_start || first>_end || last<_start || last>_end)throw std::out_of_range("erase first 或 last 超出边界");
        size_type count = last - first;
        size_type _where = first - _start;
        if (count == 0)return _start + _where;
        if (count < 0)throw std::out_of_range("erase first > last 非法");
        iterator dest = _start + _where;
        for (iterator src = dest + count; src != _end; ++dest, ++src) {
            *dest = std::move(*src);
        }
        dest = _end - count;
        while (_end != dest) {
            --_end;
            _alloc.destroy(_end);
        }
        return _start + _where;
    }
    template<class _Ty, class _Alloc>
    void vector<_Ty, _Alloc>::push_back(const reference value) {
        emplace_back(value);
    }
    template<class _Ty, class _Alloc>
    void vector<_Ty, _Alloc>::push_back(val_type&& value) {
        emplace_back(std::move(value));
    }
    template<class _Ty, class _Alloc>
    template<class... Args>
    void vector<_Ty, _Alloc>::emplace_back(Args&&... args) {
        if (_end == _end_of_storage) {
            size_type old_cap = capacity();
            size_type new_cap = old_cap == 0 ? 1 : (old_cap << 1);

            Allocator buf = std::allocator<val_type>();
            iterator _new_start = buf.allocate(old_cap + 1);
            iterator _new_end = std::uninitialized_copy(_start, _end, _new_start);
            buf.construct(_new_end, std::forward<Args>(args)...);
            ++_new_end;
            _alloc.deallocate(_start, old_cap);
            _start = _alloc.allocate(new_cap);
            _end = std::uninitialized_copy(_new_start, _new_end, _start);
            _end_of_storage = _start + new_cap;
        }
        else {
            _alloc.construct(_end, std::forward<Args>(args)...);
            ++_end;
        }
    }
    template<class _Ty, class _Alloc>
    void vector<_Ty, _Alloc>::pop_back() {
        if (_start == _end)throw std::out_of_range("pop_back 前 vector 为空");
        --_end;
        _alloc.destroy(_end);
    }
    template<class _Ty, class _Alloc>
    void vector<_Ty, _Alloc>::resize(size_type count) {
        val_type value = val_type();
        resize(count, value);
    }
    template<class _Ty, class _Alloc>
    void vector<_Ty, _Alloc>::resize(size_type count, const_reference value) {
        size_type old_cap = capacity();
        if (count <= old_cap) {
            while (_end != _start) {
                --_end;
                _alloc.destroy(_end);
            }
            _end = _start + count;
            std::uninitialized_fill(_start, _end, value);
        }
        else {
            _alloc.deallocate(_start, old_cap);
            _start = _alloc.allocate(count);
            _end = _end_of_storage = _start + count;
            std::uninitialized_fill(_start, _end, value);
        }
    }
    template<class _Ty, class _Alloc>
    void vector<_Ty, _Alloc>::swap(this_type& other) {
        std::swap(_alloc, other._alloc);
        std::swap(_start, other._start);
        std::swap(_end, other._end);
        std::swap(_end_of_storage, other._end_of_storage);
    }
}

namespace std {
    template<class _Ty, class _Alloc>
    void swap(Mystd::vector<_Ty, _Alloc>& lhs, Mystd::vector<_Ty, _Alloc>& rhs) {
        lhs.swap(rhs);
    }
    template<class _Ty, class _Alloc>
    bool operator==(const Mystd::vector<_Ty, _Alloc>& lhs, const Mystd::vector<_Ty, _Alloc>& rhs) {
        auto l_size = lhs.size(), r_size = rhs.size();
        if (l_size != r_size)return false;
        auto l_src = lhs.begin(), r_src = rhs.begin();
        for (; l_src != lhs.end(); ++l_src, ++r_src) {
            if (*l_src != *r_src) {
                return false;
            }
        }
        return true;
    }
    template<class _Ty, class _Alloc>
    bool operator!=(const Mystd::vector<_Ty, _Alloc>& lhs, const Mystd::vector<_Ty, _Alloc>& rhs) {
        auto l_size = lhs.size(), r_size = rhs.size();
        if (l_size == r_size)return false;
        auto l_src = lhs.begin(), r_src = rhs.begin();
        for (; l_src != lhs.end(); ++l_src, ++r_src) {
            if (*l_src == *r_src) {
                return false;
            }
        }
        return true;
    }
    template<class _Ty, class _Alloc>
    bool operator<(const Mystd::vector<_Ty, _Alloc>& lhs, const Mystd::vector<_Ty, _Alloc>& rhs) {
        auto l_size = lhs.size(), r_size = rhs.size();
        if (l_size == 0) return r_size != 0;
        if (r_size == 0) return false;
        auto l_src = lhs.begin(), r_src = rhs.begin();
        if (l_size < r_size) {
            for (; l_src != lhs.end(); ++l_src, ++r_src) {
                if (*(l_src) != *(r_src)) {
                    return *(l_src) < *(r_src);
                }
            }
            return true;
        }
        else {
            for (; r_src != rhs.end(); ++l_src, ++r_src) {
                if (*(l_src) != *(r_src)) {
                    return *(l_src) < *(r_src);
                }
            }
            return false;
        }
    }
    template<class _Ty, class _Alloc>
    bool operator<=(const Mystd::vector<_Ty, _Alloc>& lhs, const Mystd::vector<_Ty, _Alloc>& rhs) {
        auto l_size = lhs.size(), r_size = rhs.size();
        if (l_size == 0) return true;
        if (r_size == 0) return false;
        auto l_src = lhs.begin(), r_src = rhs.begin();
        if (l_size < r_size) {
            for (; l_src != lhs.end(); ++l_src, ++r_src) {
                if (*(l_src) != *(r_src)) {
                    return *(l_src) < *(r_src);
                }
            }
            return true;
        }
        else {
            for (; r_src != rhs.end(); ++l_src, ++r_src) {
                if (*(l_src) != *(r_src)) {
                    return *(l_src) < *(r_src);
                }
            }
            return l_size == r_size;
        }
    }
    template<class _Ty, class _Alloc>
    bool operator>(const Mystd::vector<_Ty, _Alloc>& lhs, const Mystd::vector<_Ty, _Alloc>& rhs) {
        auto l_size = lhs.size(), r_size = rhs.size();
        if (l_size == 0) return false;
        if (r_size == 0) return true;
        auto l_src = lhs.begin(), r_src = rhs.begin();
        if (l_size > r_size) {
            for (; r_src != rhs.end(); ++l_src, ++r_src) {
                if (*(l_src) != *(r_src)) {
                    return *(l_src) > *(r_src);
                }
            }
            return true;
        }
        else {
            for (; l_src != lhs.end(); ++l_src, ++r_src) {
                if (*(l_src) != *(r_src)) {
                    return *(l_src) > *(r_src);
                }
            }
            return false;
        }
    }
    template<class _Ty, class _Alloc>
    bool operator>=(const Mystd::vector<_Ty, _Alloc>& lhs, const Mystd::vector<_Ty, _Alloc>& rhs) {
        auto l_size = lhs.size(), r_size = rhs.size();
        if (r_size == 0) return true;
        if (l_size == 0) return false;
        auto l_src = lhs.begin(), r_src = rhs.begin();
        if (l_size > r_size) {
            for (; r_src != rhs.end(); ++l_src, ++r_src) {
                if (*(l_src) != *(r_src)) {
                    return *(l_src) > *(r_src);
                }
            }
            return true;
        }
        else {
            for (; l_src != lhs.end(); ++l_src, ++r_src) {
                if (*(l_src) != *(r_src)) {
                    return *(l_src) > *(r_src);
                }
            }
            return l_size == r_size;
        }
    }
}
#endif // !_MY_VECTOR_

//#include<iostream>
//#include<vector>
//#include"vector.h"
//
//#define STD Mystd
//
//template<class _Ty, class _Alloc>
//std::ostream& operator<<(std::ostream& out, const Mystd::vector<_Ty, _Alloc>& src)
//{
//    out << "size : " << src.size() << " | capacity : " << src.capacity() << " | content : ";
//    for (_Ty item : src) {
//        out << item << " ";
//    }
//    out << std::endl;
//    return out;
//}
//template<class _Ty, class _Alloc>
//std::ostream& operator<<(std::ostream& out, const std::vector<_Ty, _Alloc>& src)
//{
//    out << "size : " << src.size() << " | capacity : " << src.capacity() << " | content : ";
//    for (_Ty item : src) {
//        out << item << " ";
//    }
//    out << std::endl;
//    return out;
//}
//
//class cs {//测试类类型
//public:
//    int a;
//    int b;
//
//    cs(int x = -1) { a = b = x; }
//    cs(int _a, int _b) { a = _a; b = _b; }
//    cs(const cs& other) { a = other.a; b = other.b; }
//    friend std::ostream& operator<<(std::ostream& out, const cs& src) {
//        out << " { a = " << src.a << " b = " << src.b << "}";
//        return out;
//    }
//};
//
//int main() {
//    {
//        std::cout << "vector()" << std::endl;
//        STD::vector<int>s;
//        std::cout << "\ts : " << s;
//    }
//    {
//        std::cout << "vector(size_type count, const_reference value)" << std::endl;
//        STD::vector<int>s(5, 10);
//        std::cout << "\ts : " << s;
//    }
//    {
//        std::cout << "vector(size_type count)" << std::endl;
//        STD::vector<int>s(5);
//        std::cout << "\ts : " << s;
//    }
//    {
//        //std::cout << "template<class InputIt>\nvector(InputIt first, InputIt last, const Allocator& alloc = Allocator())" << std::endl;
//    }
//    {
//        std::cout << "vector(const this_type & other)" << std::endl;
//        STD::vector<int>s1(5, 1);
//        std::cout << "\tbefore :\n";
//        std::cout << "\t\ts1 : " << s1;
//        STD::vector<int>s2(s1);
//        std::cout << "\tafter :\n";
//        std::cout << "\t\ts1 : " << s1;
//        std::cout << "\t\ts2 : " << s2;
//    }
//    {
//        std::cout << "vector(this_type && other)" << std::endl;
//        STD::vector<int>s1(2, 3);
//        std::cout << "\tbefore :\n";
//        std::cout << "\t\ts1 : " << s1;
//        STD::vector<int>s2(std::move(s1));
//        std::cout << "\tafter :\n";
//        std::cout << "\t\ts1 : " << s1;
//        std::cout << "\t\ts2 : " << s2;
//    }
//    {
//        std::cout << "vector(std::initializer_list<val_type> init)" << std::endl;
//        STD::vector<int>s{ 1,2,3 };
//        std::cout << "\ts : " << s;
//    }
//    {
//        std::cout << "this_type& operator=(const this_type & other)" << std::endl;
//        STD::vector<int>s1(3, 2);
//        std::cout << "\tbefore :\n";
//        std::cout << "\t\ts1 : " << s1;
//        STD::vector<int>s2 = s1;
//        std::cout << "\tafter :\n";
//        std::cout << "\t\ts1 : " << s1;
//        std::cout << "\t\ts2 : " << s2;
//    }
//    {
//        std::cout << "this_type& operator=(this_type && other)" << std::endl;
//        STD::vector<int>s1(4, 3);
//        std::cout << "\tbefore :\n";
//        std::cout << "\t\ts1 : " << s1;
//        STD::vector<int>s2 = std::move(s1);
//        std::cout << "\tafter :\n";
//        std::cout << "\t\ts1 : " << s1;
//        std::cout << "\t\ts2 : " << s2;
//    }
//    {
//        std::cout << "this_type& operator=(std::initializer_list<val_type> ilist)" << std::endl;
//        STD::vector<int>s = { 3,2,4 };
//        std::cout << "\ts : " << s;
//    }
//    {
//        std::cout << "reference at(size_type pos)" << std::endl;
//        STD::vector<int>s{ 1,2,3,4 };
//        std::cout << "\t";
//        for (int i = 0; i < s.size(); ++i) {
//            std::cout << "[" << i << "] = " << s.at(i) << " ";
//        }
//        std::cout << std::endl;
//    }
//    {
//        std::cout << "reference operator[](size_type pos)" << std::endl;
//        STD::vector<int>s{ 1,2,3,4 };
//        std::cout << "\t";
//        for (int i = 0; i < s.size(); ++i) {
//            std::cout << "[" << i << "] = " << s[i] << " ";
//        }
//        std::cout << std::endl;
//    }
//    {
//        std::cout << "reference front()" << std::endl;
//        STD::vector<int>s{ 3,4,2,1 };
//        std::cout << "\t" << s;
//        std::cout << "\ts.front() = " << s.front() << std::endl;
//    }
//    {
//        std::cout << "reference back()" << std::endl;
//        STD::vector<int>s{ 3,4,2,1 };
//        std::cout << "\t" << s;
//        std::cout << "\ts.back() = " << s.back() << std::endl;
//    }
//    {
//        std::cout << "pointer data() noexcept" << std::endl;
//        STD::vector<int>s{ 3,4,2,1 };
//        int* ptr = s.data();
//        std::cout << "\t";
//        for (int i = 0; i < 4; ++i) {
//            std::cout << "[" << i << "] = " << ptr[i] << " ";
//        }
//        std::cout << std::endl << "\t" << s;
//    }
//    {
//        std::cout << "iterator begin() noexcept" << std::endl;
//        STD::vector<int>s{ 3,4,2,1 };
//        std::cout << "\t" << s;
//        std::cout << "\t*s.begin() = " << *s.begin() << std::endl;
//    }
//    {
//        std::cout << "iterator end() noexcept" << std::endl;
//        STD::vector<int>s{ 3,4,2,1 };
//        std::cout << "\t" << s;
//        std::cout << "\t*s.end() - 1 = " << *(s.end() - 1) << std::endl;
//        std::cout << "\t*(s.end() - 2) = " << *(s.end() - 2) << std::endl;
//    }
//    {
//        std::cout << "bool empty() const noexcept" << std::endl;
//        STD::vector<int>s{ 3,4,2,1 };
//        std::cout << "\t" << s;
//        std::cout << "\tis s empty? " << (s.empty() ? "true" : "false") << std::endl;
//        s = { 0 };
//        std::cout << "\t" << s;
//        std::cout << "\tis s empty? " << (s.empty() ? "true" : "false") << std::endl;
//    }
//    {
//        std::cout << "void reserve(size_type new_cap)" << std::endl;
//        STD::vector<int>s(5);
//        std::cout << "\tbefore reserve(100)\n\t\t" << s;
//        s.reserve(100);
//        std::cout << "\tafter reserve(100)\n\t\t" << s;
//        std::cout << "\tbefore reserve(2)\n\t\t" << s;
//        s.reserve(2);
//        std::cout << "\tafter reserve(2)\n\t\t" << s;
//    }
//    {
//        std::cout << "void shrink_to_fit()" << std::endl;
//        STD::vector<int>s(2, 10);
//        s.reserve(100);
//        std::cout << "\tbefore shrink_to_fit\n\t\t" << s;
//        s.shrink_to_fit();
//        std::cout << "\tafter shrink_to_fit\n\t\t" << s;
//    }
//    {
//        std::cout << "void clear() noexcept" << std::endl;
//        STD::vector<int>s{ 1, 2, 3 };
//        std::cout << "\tbefore clear\n\t\t" << s;
//        s.clear();
//        std::cout << "\tafter clear\n\t\t" << s;
//    }
//    {
//        std::cout << "iterator insert(const_iterator pos, const_reference value)" << std::endl;
//        STD::vector<int>s{ 1, 2, 3 };
//        std::cout << "\tbefore\n\t\t" << s;
//        s.insert(s.begin(), 5);
//        std::cout << "\tafter insert(s.begin(), 5)\n\t\t" << s;
//        s.insert(s.begin() + 1, 6);
//        std::cout << "\tafter insert(s.begin() + 1, 6)\n\t\t" << s;
//        s.insert(s.end(), 7);
//        std::cout << "\tafter insert(s.end(), 7)\n\t\t" << s;
//        s.insert(s.end() - 1, 8);
//        std::cout << "\tafter insert(s.end() - 1, 8)\n\t\t" << s;
//    }
//    {
//        std::cout << "iterator insert(const_iterator pos, size_type count, const_reference value)" << std::endl;
//        STD::vector<int>s{ 1, 2, 3 };
//        std::cout << "\tbefore\n\t\t" << s;
//        s.insert(s.begin(), 2, 5);
//        std::cout << "\tafter insert(s.begin(), 2, 5)\n\t\t" << s;
//        s.insert(s.begin() + 1, 3, 6);
//        std::cout << "\tafter insert(s.begin() + 1, 3, 6)\n\t\t" << s;
//        s.insert(s.end(), 2, 7);
//        std::cout << "\tafter insert(s.end(), 2, 7)\n\t\t" << s;
//        s.insert(s.end() - 1, 3, 8);
//        std::cout << "\tafter insert(s.end() - 1, 3, 8)\n\t\t" << s;
//    }
//    {
//        //std::cout << "template< class InputIt >\niterator insert(const_iterator pos, InputIt first, InputIt last)" << std::endl;
//    }
//    {
//        std::cout << "iterator insert(const_iterator pos, std::initializer_list<val_type> ilist)" << std::endl;
//        STD::vector<int>s{ 1, 2, 3 };
//        std::cout << "\tbefore\n\t\t" << s;
//        s.insert(s.begin(), { 4,5 });
//        std::cout << "\tafter insert(s.begin(), { 4, 5 })\n\t\t" << s;
//        s.insert(s.begin() + 1, { 6,7 });
//        std::cout << "\tafter insert(s.begin() + 1, { 6, 7 })\n\t\t" << s;
//        s.insert(s.end(), { 8,9 });
//        std::cout << "\tafter insert(s.end(), { 8, 9 })\n\t\t" << s;
//        s.insert(s.end() - 1, { 10,11 });
//        std::cout << "\tafter insert(s.end() - 1, {10, 11})\n\t\t" << s;
//    }
//    {
//        std::cout << "template<class... Args>\niterator emplace(const_iterator pos, Args&&... args)" << std::endl;
//        STD::vector<cs> s;
//        std::cout << "\tbefore\n\t\t" << s;
//        s.emplace(s.begin(), 1, 2);
//        std::cout << "\tafter emplace(s.begin(), 1, 2)\n\t\t" << s;
//        s.emplace(s.end(), 2);
//        std::cout << "\tafter emplace(s.end(), 2)\n\t\t" << s;
//        s.emplace(s.end(), s.front());
//        std::cout << "\tafter emplace(s.end(), s.front())\n\t\t" << s;
//        s.emplace(s.end() - 1);
//        std::cout << "\tafter emplace(s.end() - 1)\n\t\t" << s;
//    }
//    {
//        std::cout << "iterator erase(const_iterator pos)" << std::endl;
//        STD::vector<int> s{ 1,2,3,4,5 };
//        std::cout << "\tbefore\n\t\t" << s;
//        s.erase(s.begin());
//        std::cout << "\tafter erase(s.begin())\n\t\t" << s;
//        s.erase(s.end() - 1);
//        std::cout << "\tafter erase(s.end() - 1)\n\t\t" << s;
//        s.erase(s.begin() + 1);
//        std::cout << "\tafter erase(s.begin() + 1)\n\t\t" << s;
//        s.erase(s.end() - 2);
//        std::cout << "\tafter erase(s.end() - 2)\n\t\t" << s;
//    }
//    {
//        std::cout << "iterator erase(const_iterator first, const_iterator last)" << std::endl;
//        STD::vector<int> s{ 1,2,3,4,5 };
//        std::cout << "\tbefore\n\t\t" << s;
//        s.erase(s.begin(), s.begin() + 1);
//        std::cout << "\tafter erase(s.begin(), s.begin() + 1)\n\t\t" << s;
//        s.erase(s.end() - 1, s.end());
//        std::cout << "\tafter erase(s.end() -1, s.end())\n\t\t" << s;
//        s.erase(s.begin(), s.end());
//        std::cout << "\tafter erase(s.begin(), s.end())\n\t\t" << s;
//    }
//    {
//        std::cout << "void push_back(const reference value)" << std::endl;
//        STD::vector<int> s;
//        std::cout << "\tbefore\n\t\t" << s;
//        s.push_back(1);
//        std::cout << "\tafter push_back(1)\n\t\t" << s;
//        s.push_back(3);
//        std::cout << "\tafter push_back(3)\n\t\t" << s;
//        s.push_back(2);
//        std::cout << "\tafter push_back(2)\n\t\t" << s;
//    }
//    {
//        std::cout << "template<class... Args>\nvoid emplace_back(Args&&... args)" << std::endl;
//        STD::vector<cs> s;
//        std::cout << "\tbefore\n\t\t" << s;
//        s.emplace_back(1, 2);
//        std::cout << "\tafter emplace_back(1, 2)\n\t\t" << s;
//        s.emplace_back(2);
//        std::cout << "\tafter emplace_back(2)\n\t\t" << s;
//        s.emplace_back(s.front());
//        std::cout << "\tafter emplace_back(s.front())\n\t\t" << s;
//        s.emplace_back();
//        std::cout << "\tafter emplace_back()\n\t\t" << s;
//    }
//    {
//        std::cout << "void pop_back()" << std::endl;
//        STD::vector<int> s{ 1,2,3,4 };
//        std::cout << "\tbefore\n\t\t" << s;
//        s.pop_back();
//        std::cout << "\tafter pop_back()\n\t\t" << s;
//        s.pop_back();
//        std::cout << "\tafter pop_back()\n\t\t" << s;
//        s.pop_back();
//        std::cout << "\tafter pop_back()\n\t\t" << s;
//        s.pop_back();
//        std::cout << "\tafter pop_back()\n\t\t" << s;
//    }
//    {
//        std::cout << "void resize(size_type count)" << std::endl;
//        STD::vector<int> s;
//        std::cout << "\tbefore\n\t\t" << s;
//        s.resize(10);
//        std::cout << "\tafter resize(10)\n\t\t" << s;
//        s.resize(5);
//        std::cout << "\tafter resize(5)\n\t\t" << s;
//        s.resize(0);
//        std::cout << "\tafter resize(0)\n\t\t" << s;
//    }
//    {
//        std::cout << "void resize(size_type count, const_reference value)" << std::endl;
//        STD::vector<int> s;
//        std::cout << "\tbefore\n\t\t" << s;
//        s.resize(5, 2);
//        std::cout << "\tafter resize(5, 2)\n\t\t" << s;
//        s.resize(2, 3);
//        std::cout << "\tafter resize(2, 3)\n\t\t" << s;
//        s.resize(0, 1);
//        std::cout << "\tafter resize(0, 1)\n\t\t" << s;
//    }
//    {
//        std::cout << "void swap(this_type & other)" << std::endl;
//        STD::vector<int> s1 = { 1,2,3 };
//        STD::vector<int> s2 = { 4,5,6 };
//        std::cout << "\tbefore\n\t\ts1 :" << s1 << "\t\ts2:" << s2;
//        s1.swap(s2);
//        std::cout << "\tafter swap()\n\t\ts1 :" << s1 << "\t\ts2:" << s2;
//    }
//}