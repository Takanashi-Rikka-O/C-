C_template_class.cpp:169:17: error: default argument for template parameter for class enclosing ‘CLASS::BASE<Any>::BASE()’
 BASE<Any>::BASE()
                 ^
C_template_class.cpp:176:18: error: default argument for template parameter for class enclosing ‘CLASS::BASE<Any>::~BASE()’
 BASE<Any>::~BASE()
                  ^
C_template_class.cpp:183:34: error: default argument for template parameter for class enclosing ‘void CLASS::BASE<Any>::View_Value1() const’
 void BASE<Any>::View_Value1(void)const
                                  ^
C_template_class.cpp:189:34: error: no ‘void CLASS::BASE<Any>::View_Value2() const’ member function declared in class ‘CLASS::BASE<Any>’
 void BASE<Any>::View_Value2(void)const
                                  ^
C_template_class.cpp:201:72: error: default argument specified in explicit specialization [-fpermissive]
 BASE<const char*>::BASE(const char* tmp1="NULL",const char* tmp2="NULL")
                                                                        ^
C_template_class.cpp:201:1: error: template-id ‘BASE<>’ for ‘CLASS::BASE<const char*>::BASE(const char*, const char*)’ does not match any template declaration
 BASE<const char*>::BASE(const char* tmp1="NULL",const char* tmp2="NULL")
 ^
C_template_class.cpp:219:1: error: template-id ‘BASE<>’ for ‘CLASS::BASE<const char*>::~BASE()’ does not match any template declaration
 BASE<const char*>::~BASE()
 ^
C_template_class.cpp:235:6: error: template-id ‘View_Value1<>’ for ‘void CLASS::BASE<const char*>::View_Value1() const’ does not match any template declaration
 void BASE<const char*>::View_Value1(void)const
      ^
C_template_class.cpp:242:6: error: template-id ‘View_Value2<>’ for ‘void CLASS::BASE<const char*>::View_Value2() const’ does not match any template declaration
 void BASE<const char*>::View_Value2(void)const
      ^
C_template_class.cpp: In function ‘int main()’:
C_template_class.cpp:261:7: error: missing template arguments before ‘subject1’
  BASE subject1;    // Because Any=int,so here will be using default type.
       ^
C_template_class.cpp:261:7: error: expected ‘;’ before ‘subject1’
C_template_class.cpp:265:38: error: no matching function for call to ‘CLASS::BASE<char*>::BASE(const char [5], const char [7])’
  BASE<char*> subject2("KKSK","FUBUKI"); 
                                      ^
C_template_class.cpp:265:38: note: candidates are:
C_template_class.cpp:169:1: note: CLASS::BASE<Any>::BASE() [with Any = char*]
 BASE<Any>::BASE()
 ^
C_template_class.cpp:169:1: note:   candidate expects 0 arguments, 2 provided
C_template_class.cpp:129:8: note: constexpr CLASS::BASE<char*>::BASE(const CLASS::BASE<char*>&)
  class BASE    // A template of class.Type is normal-type 'Any'.
        ^
C_template_class.cpp:129:8: note:   candidate expects 1 argument, 2 provided
C_template_class.cpp:268:2: error: ‘subject1’ was not declared in this scope
  subject1.View_Value1();
  ^
C_template_class.cpp:273:11: error: ‘class CLASS::BASE<char*>’ has no member named ‘View_Value2’
  subject2.View_Value2();
           ^
C_template_class.cpp: In instantiation of ‘void CLASS::BASE<Any>::View_Value1() const [with Any = char*]’:
C_template_class.cpp:272:23:   required from here
C_template_class.cpp:185:30: error: no match for ‘operator<<’ (operand types are ‘std::basic_ostream<char>’ and ‘<unresolved overloaded function type>’)
  cout<<"Value one = "<<value1<<end;
                              ^
C_template_class.cpp:185:30: note: candidates are:
In file included from /usr/include/c++/4.8.2/iostream:39:0,
                 from C_template_class.cpp:1:
/usr/include/c++/4.8.2/ostream:108:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(std::basic_ostream<_CharT, _Traits>::__ostream_type& (*)(std::basic_ostream<_CharT, _Traits>::__ostream_type&)) [with _CharT = char; _Traits = std::char_traits<char>; std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
       operator<<(__ostream_type& (*__pf)(__ostream_type&))
       ^
/usr/include/c++/4.8.2/ostream:108:7: note:   no known conversion for argument 1 from ‘<unresolved overloaded function type>’ to ‘std::basic_ostream<char>::__ostream_type& (*)(std::basic_ostream<char>::__ostream_type&) {aka std::basic_ostream<char>& (*)(std::basic_ostream<char>&)}’
/usr/include/c++/4.8.2/ostream:117:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(std::basic_ostream<_CharT, _Traits>::__ios_type& (*)(std::basic_ostream<_CharT, _Traits>::__ios_type&)) [with _CharT = char; _Traits = std::char_traits<char>; std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>; std::basic_ostream<_CharT, _Traits>::__ios_type = std::basic_ios<char>]
       operator<<(__ios_type& (*__pf)(__ios_type&))
       ^
/usr/include/c++/4.8.2/ostream:117:7: note:   no known conversion for argument 1 from ‘<unresolved overloaded function type>’ to ‘std::basic_ostream<char>::__ios_type& (*)(std::basic_ostream<char>::__ios_type&) {aka std::basic_ios<char>& (*)(std::basic_ios<char>&)}’
/usr/include/c++/4.8.2/ostream:127:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(std::ios_base& (*)(std::ios_base&)) [with _CharT = char; _Traits = std::char_traits<char>; std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
       operator<<(ios_base& (*__pf) (ios_base&))
       ^
/usr/include/c++/4.8.2/ostream:127:7: note:   no known conversion for argument 1 from ‘<unresolved overloaded function type>’ to ‘std::ios_base& (*)(std::ios_base&)’
/usr/include/c++/4.8.2/ostream:166:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(long int) [with _CharT = char; _Traits = std::char_traits<char>; std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
       operator<<(long __n)
       ^
/usr/include/c++/4.8.2/ostream:166:7: note:   no known conversion for argument 1 from ‘<unresolved overloaded function type>’ to ‘long int’
/usr/include/c++/4.8.2/ostream:170:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(long unsigned int) [with _CharT = char; _Traits = std::char_traits<char>; std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
       operator<<(unsigned long __n)
       ^
/usr/include/c++/4.8.2/ostream:170:7: note:   no known conversion for argument 1 from ‘<unresolved overloaded function type>’ to ‘long unsigned int’
/usr/include/c++/4.8.2/ostream:174:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(bool) [with _CharT = char; _Traits = std::char_traits<char>; std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
       operator<<(bool __n)
       ^
/usr/include/c++/4.8.2/ostream:174:7: note:   no known conversion for argument 1 from ‘<unresolved overloaded function type>’ to ‘bool’
In file included from /usr/include/c++/4.8.2/ostream:612:0,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from C_template_class.cpp:1:
/usr/include/c++/4.8.2/bits/ostream.tcc:91:5: note: std::basic_ostream<_CharT, _Traits>& std::basic_ostream<_CharT, _Traits>::operator<<(short int) [with _CharT = char; _Traits = std::char_traits<char>]
     basic_ostream<_CharT, _Traits>::
     ^
/usr/include/c++/4.8.2/bits/ostream.tcc:91:5: note:   no known conversion for argument 1 from ‘<unresolved overloaded function type>’ to ‘short int’
In file included from /usr/include/c++/4.8.2/iostream:39:0,
                 from C_template_class.cpp:1:
/usr/include/c++/4.8.2/ostream:181:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(short unsigned int) [with _CharT = char; _Traits = std::char_traits<char>; std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
       operator<<(unsigned short __n)
       ^
/usr/include/c++/4.8.2/ostream:181:7: note:   no known conversion for argument 1 from ‘<unresolved overloaded function type>’ to ‘short unsigned int’
In file included from /usr/include/c++/4.8.2/ostream:612:0,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from C_template_class.cpp:1:
/usr/include/c++/4.8.2/bits/ostream.tcc:105:5: note: std::basic_ostream<_CharT, _Traits>& std::basic_ostream<_CharT, _Traits>::operator<<(int) [with _CharT = char; _Traits = std::char_traits<char>]
     basic_ostream<_CharT, _Traits>::
     ^
/usr/include/c++/4.8.2/bits/ostream.tcc:105:5: note:   no known conversion for argument 1 from ‘<unresolved overloaded function type>’ to ‘int’
In file included from /usr/include/c++/4.8.2/iostream:39:0,
                 from C_template_class.cpp:1:
/usr/include/c++/4.8.2/ostream:192:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(unsigned int) [with _CharT = char; _Traits = std::char_traits<char>; std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
       operator<<(unsigned int __n)
       ^
/usr/include/c++/4.8.2/ostream:192:7: note:   no known conversion for argument 1 from ‘<unresolved overloaded function type>’ to ‘unsigned int’
/usr/include/c++/4.8.2/ostream:201:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(long long int) [with _CharT = char; _Traits = std::char_traits<char>; std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
       operator<<(long long __n)
       ^
/usr/include/c++/4.8.2/ostream:201:7: note:   no known conversion for argument 1 from ‘<unresolved overloaded function type>’ to ‘long long int’
/usr/include/c++/4.8.2/ostream:205:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(long long unsigned int) [with _CharT = char; _Traits = std::char_traits<char>; std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
       operator<<(unsigned long long __n)
       ^
/usr/include/c++/4.8.2/ostream:205:7: note:   no known conversion for argument 1 from ‘<unresolved overloaded function type>’ to ‘long long unsigned int’
/usr/include/c++/4.8.2/ostream:220:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(double) [with _CharT = char; _Traits = std::char_traits<char>; std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
       operator<<(double __f)
       ^
/usr/include/c++/4.8.2/ostream:220:7: note:   no known conversion for argument 1 from ‘<unresolved overloaded function type>’ to ‘double’
/usr/include/c++/4.8.2/ostream:224:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(float) [with _CharT = char; _Traits = std::char_traits<char>; std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
       operator<<(float __f)
       ^
/usr/include/c++/4.8.2/ostream:224:7: note:   no known conversion for argument 1 from ‘<unresolved overloaded function type>’ to ‘float’
/usr/include/c++/4.8.2/ostream:232:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(long double) [with _CharT = char; _Traits = std::char_traits<char>; std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
       operator<<(long double __f)
       ^
/usr/include/c++/4.8.2/ostream:232:7: note:   no known conversion for argument 1 from ‘<unresolved overloaded function type>’ to ‘long double’
/usr/include/c++/4.8.2/ostream:245:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(const void*) [with _CharT = char; _Traits = std::char_traits<char>; std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
       operator<<(const void* __p)
       ^
/usr/include/c++/4.8.2/ostream:245:7: note:   no known conversion for argument 1 from ‘<unresolved overloaded function type>’ to ‘const void*’
In file included from /usr/include/c++/4.8.2/ostream:612:0,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from C_template_class.cpp:1:
/usr/include/c++/4.8.2/bits/ostream.tcc:119:5: note: std::basic_ostream<_CharT, _Traits>& std::basic_ostream<_CharT, _Traits>::operator<<(std::basic_ostream<_CharT, _Traits>::__streambuf_type*) [with _CharT = char; _Traits = std::char_traits<char>; std::basic_ostream<_CharT, _Traits>::__streambuf_type = std::basic_streambuf<char>]
     basic_ostream<_CharT, _Traits>::
     ^
/usr/include/c++/4.8.2/bits/ostream.tcc:119:5: note:   no known conversion for argument 1 from ‘<unresolved overloaded function type>’ to ‘std::basic_ostream<char>::__streambuf_type* {aka std::basic_streambuf<char>*}’
In file included from /usr/include/c++/4.8.2/string:52:0,
                 from /usr/include/c++/4.8.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.8.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.8.2/ios:42,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from C_template_class.cpp:1:
/usr/include/c++/4.8.2/bits/basic_string.h:2753:5: note: template<class _CharT, class _Traits, class _Alloc> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, const std::basic_string<_CharT, _Traits, _Alloc>&)
     operator<<(basic_ostream<_CharT, _Traits>& __os,
     ^
/usr/include/c++/4.8.2/bits/basic_string.h:2753:5: note:   template argument deduction/substitution failed:
C_template_class.cpp:185:30: note:   couldn't deduce template parameter ‘_Alloc’
  cout<<"Value one = "<<value1<<end;
                              ^
In file included from /usr/include/c++/4.8.2/iostream:39:0,
                 from C_template_class.cpp:1:
/usr/include/c++/4.8.2/ostream:471:5: note: std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, _CharT) [with _CharT = char; _Traits = std::char_traits<char>]
     operator<<(basic_ostream<_CharT, _Traits>& __out, _CharT __c)
     ^
/usr/include/c++/4.8.2/ostream:471:5: note:   no known conversion for argument 2 from ‘<unresolved overloaded function type>’ to ‘char’
/usr/include/c++/4.8.2/ostream:476:5: note: template<class _CharT, class _Traits> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, char)
     operator<<(basic_ostream<_CharT, _Traits>& __out, char __c)
     ^
/usr/include/c++/4.8.2/ostream:476:5: note:   template argument deduction/substitution failed:
C_template_class.cpp:185:30: note:   cannot convert ‘std::end’ (type ‘<unresolved overloaded function type>’) to type ‘char’
  cout<<"Value one = "<<value1<<end;
                              ^
In file included from /usr/include/c++/4.8.2/iostream:39:0,
                 from C_template_class.cpp:1:
/usr/include/c++/4.8.2/ostream:482:5: note: template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(std::basic_ostream<char, _Traits>&, char)
     operator<<(basic_ostream<char, _Traits>& __out, char __c)
     ^
/usr/include/c++/4.8.2/ostream:482:5: note:   template argument deduction/substitution failed:
C_template_class.cpp:185:30: note:   cannot convert ‘std::end’ (type ‘<unresolved overloaded function type>’) to type ‘char’
  cout<<"Value one = "<<value1<<end;
                              ^
In file included from /usr/include/c++/4.8.2/iostream:39:0,
                 from C_template_class.cpp:1:
/usr/include/c++/4.8.2/ostream:488:5: note: template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(std::basic_ostream<char, _Traits>&, signed char)
     operator<<(basic_ostream<char, _Traits>& __out, signed char __c)
     ^
/usr/include/c++/4.8.2/ostream:488:5: note:   template argument deduction/substitution failed:
C_template_class.cpp:185:30: note:   cannot convert ‘std::end’ (type ‘<unresolved overloaded function type>’) to type ‘signed char’
  cout<<"Value one = "<<value1<<end;
                              ^
In file included from /usr/include/c++/4.8.2/iostream:39:0,
                 from C_template_class.cpp:1:
/usr/include/c++/4.8.2/ostream:493:5: note: template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(std::basic_ostream<char, _Traits>&, unsigned char)
     operator<<(basic_ostream<char, _Traits>& __out, unsigned char __c)
     ^
/usr/include/c++/4.8.2/ostream:493:5: note:   template argument deduction/substitution failed:
C_template_class.cpp:185:30: note:   cannot convert ‘std::end’ (type ‘<unresolved overloaded function type>’) to type ‘unsigned char’
  cout<<"Value one = "<<value1<<end;
                              ^
In file included from /usr/include/c++/4.8.2/iostream:39:0,
                 from C_template_class.cpp:1:
/usr/include/c++/4.8.2/ostream:513:5: note: std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, const _CharT*) [with _CharT = char; _Traits = std::char_traits<char>]
     operator<<(basic_ostream<_CharT, _Traits>& __out, const _CharT* __s)
     ^
/usr/include/c++/4.8.2/ostream:513:5: note:   no known conversion for argument 2 from ‘<unresolved overloaded function type>’ to ‘const char*’
In file included from /usr/include/c++/4.8.2/ostream:612:0,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from C_template_class.cpp:1:
/usr/include/c++/4.8.2/bits/ostream.tcc:321:5: note: template<class _CharT, class _Traits> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, const char*)
     operator<<(basic_ostream<_CharT, _Traits>& __out, const char* __s)
     ^
/usr/include/c++/4.8.2/bits/ostream.tcc:321:5: note:   template argument deduction/substitution failed:
C_template_class.cpp:185:30: note:   cannot convert ‘std::end’ (type ‘<unresolved overloaded function type>’) to type ‘const char*’
  cout<<"Value one = "<<value1<<end;
                              ^
In file included from /usr/include/c++/4.8.2/iostream:39:0,
                 from C_template_class.cpp:1:
/usr/include/c++/4.8.2/ostream:530:5: note: template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(std::basic_ostream<char, _Traits>&, const char*)
     operator<<(basic_ostream<char, _Traits>& __out, const char* __s)
     ^
/usr/include/c++/4.8.2/ostream:530:5: note:   template argument deduction/substitution failed:
C_template_class.cpp:185:30: note:   cannot convert ‘std::end’ (type ‘<unresolved overloaded function type>’) to type ‘const char*’
  cout<<"Value one = "<<value1<<end;
                              ^
In file included from /usr/include/c++/4.8.2/iostream:39:0,
                 from C_template_class.cpp:1:
/usr/include/c++/4.8.2/ostream:543:5: note: template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(std::basic_ostream<char, _Traits>&, const signed char*)
     operator<<(basic_ostream<char, _Traits>& __out, const signed char* __s)
     ^
/usr/include/c++/4.8.2/ostream:543:5: note:   template argument deduction/substitution failed:
C_template_class.cpp:185:30: note:   cannot convert ‘std::end’ (type ‘<unresolved overloaded function type>’) to type ‘const signed char*’
  cout<<"Value one = "<<value1<<end;
                              ^
In file included from /usr/include/c++/4.8.2/iostream:39:0,
                 from C_template_class.cpp:1:
/usr/include/c++/4.8.2/ostream:548:5: note: template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(std::basic_ostream<char, _Traits>&, const unsigned char*)
     operator<<(basic_ostream<char, _Traits>& __out, const unsigned char* __s)
     ^
/usr/include/c++/4.8.2/ostream:548:5: note:   template argument deduction/substitution failed:
C_template_class.cpp:185:30: note:   cannot convert ‘std::end’ (type ‘<unresolved overloaded function type>’) to type ‘const unsigned char*’
  cout<<"Value one = "<<value1<<end;
                              ^
In file included from /usr/include/c++/4.8.2/iostream:39:0,
                 from C_template_class.cpp:1:
/usr/include/c++/4.8.2/ostream:602:5: note: template<class _CharT, class _Traits, class _Tp> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&&, const _Tp&)
     operator<<(basic_ostream<_CharT, _Traits>&& __os, const _Tp& __x)
     ^
/usr/include/c++/4.8.2/ostream:602:5: note:   template argument deduction/substitution failed:
C_template_class.cpp:185:30: note:   couldn't deduce template parameter ‘_Tp’
  cout<<"Value one = "<<value1<<end;
                              ^
