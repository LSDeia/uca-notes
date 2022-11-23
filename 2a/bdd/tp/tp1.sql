-- Q2
select city
from team
where nickname='Grizzlies';

-- Q3
select max(ptsHome)
from game;

-- Q4
select max(ptsAway)
from game;

-- Q5

-- Q6
select t.abbreviation, t.nickname, t.city, g.ptsHome, g.dateGame
from game g, team t
where t.id = g.idHomeTeam and g.ptsHome = (select max(ptsHome) from game);

-- Q7
select t.abbreviation, t.nickname, t.city, g.ptsAway, g.dateGame
from game g, team t
where t.id = g.idVisitorTeam and g.ptsAway = (select max(ptsHome) from game);

-- Q8
select p.name
from player p, gamedetail gd
where p.id = gd.idPlayer and gd.threePointsPrctage = (select max(threePointsPrctage) from gamedetail)
group by p.name
order by p.name;

-- Q9
select p.name
from player p, gamedetail gd, game g
where p.id = gd.idPlayer and  g.id = gd.idGame and dateGame > '2004-01-01' and  g.dateGame < '2021-12-31' and  gd.threePointsPrctage >= (select avg(threePointsPrctage) from gamedetail)
group by p.name
order by p.name;

-- Q10
select max(threePointsMade)
from gamedetail gd, player p, game g
where gd.idGame = g.id and to_char(g.dateGame,'YYYY') = '2012' and gd.idPlayer = p.id;

-- Q11
select t1.nickname, t1.conference, t2.nickname, t2.conference
from team t1, team t2
where t1.conference = 'W' and t2.conference = 'E' and t1.yearFounded = (select max(yearFounded) from team where conference = 'W') and t2.yearFounded = (select max(yearFounded) from team where conference = 'E');

-- Q12
select p.name, g.dateGame
from player p, gamedetail gd, game g
where gd.idPlayer = p.id and g.id = gd.idGame and gd.assists >= (select max(assists) from gamedetail);

-- Q13
select p.name, g.dateGame
from player p, gamedetail gd, game g
where gd.idPlayer = p.id and g.id = gd.idGame and personnalFoul = 6 and playingTime >= (select min(playingTime) from gamedetail);

select min(playingTime)
from gamedetail
where personnalFoul = 6;



















