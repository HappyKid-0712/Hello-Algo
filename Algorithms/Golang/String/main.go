package main

import "fmt"

type String struct {
	ch     []byte
	Length int
}

func (s String) Index(sub String) (index int) {
	var (
		n = s.Length
		m = sub.Length
		i = 1
		j = 1
	)

	for i <= n && j <= m {
		if s.ch[i] == sub.ch[j] {
			i++
			j++
		} else {
			i = i - j + 2
			j = 1
		}
	}

	//说明不仅跑完了而且还匹配完了，那么就是匹配成功了
	if j > m {
		index = i - m
	} else {
		//说明匹配失败了，返回 0
		index = 0
	}
	return
}

func main() {
	mainStr := String{
		[]byte(" hello world"),
		11,
	}
	subStr := String{
		[]byte(" world"),
		5,
	}
	fmt.Println(mainStr.Index(subStr))
}
