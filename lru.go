type LRUCache struct {
    kv map[int]int
    life map[int]int
    capacity int
}


func Constructor(capacity int) LRUCache {
    return LRUCache{
    	kv : map[int]int{},
    	life : map[int]int{},
    	capacity :	capacity,
    }
}


func (this *LRUCache) Get(key int) int {
    if val, exist := this.kv[key]; exist {
    	for k := range this.life {
    		this.life[k]--
    	}
    	this.life[key] = this.capacity
    	return val
    } else {
    	return -1
    }
}


func (this *LRUCache) Put(key int, value int)  {
	oldestKey := -1
	for k := range this.kv {
		this.life[k]--
		if this.life[k] <= 0 {
			oldestKey = k
		}
	}
	this.kv[key] = value
	this.life[key] = this.capacity
    if len(this.kv) > this.capacity {
    	delete(this.kv, oldestKey)
    	delete(this.life, oldestKey)
    }
}


/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */