#!/usr/bin/env crystal
T={
	1=>{
		[[1]],
		->(h : Int32){true},
	},
	2=>{
		[[2],[2]],
		->(h : Int32){h==0||h==1||h==3},
	},
	3=>{
		[[3],[3],[3]],
		->(h : Int32){h==0},
	},
	4=>{
		[[4,4],[4,4]],
		->(h : Int32){h==3},
	},
	5=>{
		[[5],[5],[5],[5],[5]],
		->(h : Int32){h==0},
	},
	6=>{
		[[6,6],[6,6],[6,6]],
		->(h : Int32){h==0},
	},
}

Memo={} of Array(Int32) => Int64
def dfs(m,x,y)
	if x==0 && y==m.size
		return 1
	end
	m0=m.flatten
	if Memo.has_key?(m0)
		return Memo[m0]
	end
	if x==m[y].size
		return dfs(m,0,y+1)
	end
	if m[y][x]!=0
		return dfs(m,x+1,y)
	end
	r=0_i64
	T.each{|k,v|
		next if !v[1].call(y)
		e=v[0]
		if e.size.times.all?{|y0|e[y0].size.times.all?{|x0|
			y+y0<m.size && x+x0<m[y+y0].size && m[y+y0][x+x0]==0
		}}
			e.size.times{|y0|e[y0].size.times{|x0|m[y+y0][x+x0]=1}} # e[y0][x0]}}
			r+=dfs(m,x+1,y)
			e.size.times{|y0|e[y0].size.times{|x0|m[y+y0][x+x0]=0}}
		end
	}
	Memo[m0]=r
end

w=12
h=5
m=h.times.map{[0]*w}.to_a
puts dfs(m,0,0)
