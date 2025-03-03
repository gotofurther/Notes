# STL
------
* HEAPS:
    > A heap is a data structure that looks like a tree. But it has a property that every node must be smaller than its children
    > A max heap which relationship between parents and children is the parents is bigger
    * std::make_heap(begin(numbers), end(numbers));
    * std::push_heap(begin(numbers), end(numbers));
        numbers.push_heap(numbers_one);
    * std::pop_heap(begin(numbers), end(numbers));
        numbers.pop_heap();
* SORT:
    * sort
    * partial_sort
        ![1740964676302](image/Cpp-STL/1740964676302.png)
    * nth_element
        ![1740964737204](image/Cpp-STL/1740964737204.png)
    * sort_heap
    * inplace_merge
* PARTIONING
    * partition


---------------
---------------

* Vector:
    * ����:
        * vector<typename>name;
        * typename�������κλ�����������, ��int, double, char, Ҳ�������κ��Զ�������, ��ṹ��struct, ��������������STL����, ��vector����, set, queue��.
        * ������typenameΪ��һ��STL����ʱ, ����vector<vector<int> >, ��>>Ҫ���Ͽո�, �����ϱ�����������ʶ��Ϊ��λ������
    * ����:
        * vector֧���±����, ������ͨ����һ��, ����ʹ��vectorname[index]����ʽ�����ʻ��޸�����Ԫ��, ���ʴ�0��ʼ, ֱ��vectorname.size()-1
        * Ҳ����ͨ������������, ����������﷨��: vector<typename>::iterator it;
            * ʾ��:
            ```c++
            vector<int>::iterator it = vi.begin();
            ```
            ```c++
            vector<int>::iterator it = vi.begin();
            for(int i = 0; i < vi.size(); i++){
                printf("%d ", *(it + i));//���vi[i]
            }
            ```
    * ���ú���:
        * push_back(element): ��vector��ĩβ���һ����Ԫ��
        * pop_back(): ɾ��vector�е����һ��Ԫ��
        * size(): ����vector��Ԫ�ظ���
        * clear(): ɾ��vector�е�����Ԫ��, ʹ���Ϊ��
        * insert(it, element): ��ָ��������λ�ò���һ����Ԫ��
        * erase(it): ɾ��ָ��������λ�õ�Ԫ��
* Set:
    > set����ȷ�������ڲ�����Ԫ�ض���Ψһ��, �Զ�ȥ���ظ�Ԫ��, �Ҹ������е�Ԫ�ػᰴ��һ����˳������, Ĭ�������������
    * ����:
        * set<typename>name;
        * ͬ��, ���е�typename�������κλ�����������, Ҳ�������κ��Զ�������, Ҳ����STL����
    * ����:
        * set��֧���±����Ԫ��, ����ֻ��ͨ������������
        * ͬ��, ����set<typename>:: iterator it = st,begin();
    * ���ú���:
        * insert(element): ��һ����Ԫ�ز���set��
        * find(element): ��set�в���һ��Ԫ��
        * erase(element): ɾ��set��ָ����Ԫ��
        * size(): ����set��Ԫ�صĸ���
        * clear(): ɾ��set�е�����Ԫ��
* String:
    * ���ú���:
        * length()/size(): ��ȡ�ַ�������
        * find(): ����
        * substr(): ���Ӵ�
        * append(): ����ַ���
        * compare(): �Ƚ��ַ��� s1.compare(s2)
        * tolower()/toupper(): �ַ���ת��Сд tolower(s1)
* ��̬�滮:
