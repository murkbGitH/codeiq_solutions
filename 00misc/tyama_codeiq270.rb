#!/usr/bin/ruby
require 'bigdecimal'
dt=BigDecimal('0.1')
t=BigDecimal('1364778000')
e=BigDecimal('1364871600')
#raise 't and e are invalid' if t>=e
while t<e
	d=e-t
	t+=d
	e+=d*dt
end
puts t

__END__
この問題が公開された4/1 10:00時点でのunix time(1364778000)をtと置こう。
この問題の挑戦締め切りは4/2 12:00だから、その時刻に地球が滅亡すると予想することにして、そのunix time(1364871600)をeと置こう。
ところが、今まで地球が滅亡するとされながらも滅亡しなかった。これは、現在時刻が進むにつれ、滅亡する時刻も(当時の予想よりも)徐々に進んでいるからだと思われる。
ここでは、現在時刻がその時点での地球が滅亡する時刻に進むとき、その時間をtとすると、地球が滅亡する時刻はそのdt倍だけ進んでいることにしよう(「徐々に進む」なので、0<dt<1)。
すると、次の計算が正常に終了した時点での時刻tが「地球が滅亡する日」ということになる。ところが、我々にはこの計算を正常に終了させる術はない。
よって地球が滅亡する日を計算によって予測することはできない。
なお、t>=eなるパラメータを以ってプログラムを実行しても、その結果に意味は無いことに注意されたい。