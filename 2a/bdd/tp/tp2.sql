--create index idx on gamedetail(personnalFoul);

select t1.nickname, t2.nickname, g.dateGame
from player p, gamedetail gd, game g, team t1, team t2
where (gd.idTeam=g.idHomeTeam or gd.idTeam=g.idVisitorTeam) and t1.id=g.idHomeTeam and t2.id=g.idVisitorTeam and
gd.idPlayer=p.id and g.id=gd.idGame and gd.personnalFoul=6 and gd.playingTime>=(select min(playingTime) from gamedetail);