-- Q1
/*
create or replace function q1 (match GameDetail.idGame%TYPE) returns integer as $$
DECLARE
    nb_rebounds integer;
begin
    select sum(gd.rebounds) into nb_rebounds
    from GameDetail gd
    where gd.idGame = match and gd.startPosition is null;

    return nb_rebounds;
end;
$$ language plpgsql;

select q1('22101005');

-- Q1 P2

create or replace function q1p2 (match GameDetail.idGame%TYPE) returns integer as $$
DECLARE
    nb_rebounds GameDetail.rebounds%TYPE := 0;
    rebounds_cursor cursor for select gd.rebounds
                                from GameDetail gd
                                where gd.idGame = match and gd.startPosition is null and gd.rebounds is not null;
begin
    for i in rebounds_cursor LOOP
            nb_rebounds := nb_rebounds + i.rebounds;
    end loop;

    return nb_rebounds;
end;
$$ language plpgsql;

select q1p2('22101005');

-- Q2

select q1(id), q1p2(id) from game where dateGame = '2022-03-12';

create or replace function q2 () returns table(r1 GameDetail.rebounds%TYPE, r2 GameDetail.rebounds%TYPE) as $$
DECLARE
    id_cursor cursor for select distinct gd.idGame
                                from GameDetail gd, Game g
                                where gd.idGame = g.id and g.dateGame = '2022-03-12';
begin
    for i in id_cursor LOOP
            r1 := select q1(i.idGame);
            r2 := select q1p2(i.idGame);
    end loop;
end;
$$ language plpgsql;

select q2();


-- Q3

create or replace function q3 (match GameDetail.idGame%TYPE) returns integer as $$
DECLARE
    nb_rebounds integer;
begin
    select sum(gd.rebounds) into nb_rebounds
    from GameDetail gd
    where gd.idGame = match and gd.startPosition is not null;

    return nb_rebounds;
end;
$$ language plpgsql;

create or replace function q3p2 (match GameDetail.idGame%TYPE) returns integer as $$
DECLARE
    nb_rebounds GameDetail.rebounds%TYPE := 0;
    rebounds_cursor cursor for select gd.rebounds
                                from GameDetail gd
                                where gd.idGame = match and gd.startPosition is not null and gd.rebounds is not null;
begin
    for i in rebounds_cursor LOOP
            nb_rebounds := nb_rebounds + i.rebounds;
    end loop;

    return nb_rebounds;
end;
$$ language plpgsql;

select id, q3(id), q3p2(id) from game where dateGame = '2022-03-12';
*/

-- Q4

-- select id, q3(id), q3p2(id) from game;
/*
SELECT g.dateGame, t1.nickname, t2.nickname
from Game g, Team t1, Team t2
where t1.id = g.idHomeTeam and t2.id = g.idVisitorTeam and g.id = (select g.id
                                                                    from game g
                                                                    where g.id = gd.idGame)
*/

-- Q5
/*
create or replace function q5(match GameDetail.idGame%TYPE) returns integer as $$
DECLARE
    nb_rebounds integer;
begin
    select sum(gd.rebounds) into nb_rebounds
    from GameDetail gd
    where gd.idGame = match;

    return nb_rebounds;
end;
$$ language plpgsql;

select q5('22101005');

create or replace function q5p2 (match Game.id%TYPE) returns integer as $$
DECLARE
    home_rebounds integer := 0;
    away_rebounds integer := 0;
begin
    select g.reboundsHome into home_rebounds
    from Game g;

    select g.reboundsAway into away_rebounds
    from Game g;

    return home_rebounds + away_rebounds;
end;
$$ language plpgsql;

select q5p2('22101005');

create or replace function q5Check () RETURNS void AS $$
DECLARE
    gamed integer := 0;
    game integer := 0;
    id_cursor cursor for select g.id from Game g;

BEGIN
    for i in id_cursor LOOP
            game := q5(i.id);
            gamed := q5p2(i.id);
            
            if game = gamed then
                raise notice 'Game %: check = true', i.id;
            else
                raise notice 'Game %: check = false', i.id;
            end if;
    end loop;
end;create or replace function bestAtHome()
RETURNS table (id Team) AS $$
DECLARE
    Home integer := 0;
    Away integer := 0;
    id_cursor cursor for select g.id, g.homeTeamWins, g.idHomeTeam, g.idVisitorTeam
                         from Game g
                         where team = g.idHomeTeam or team = g.idVisitorTeam and season = '2021';

BEGIN
    for i in id_cursor LOOP
            if i.homeTeamWins and team = i.idHomeTeam then
                Home := Home + 1;
            elsif i.homeTeamWins and team = i.idVisitorTeam then
                Away := Away + 1;
            end if;
    end loop;
    return Home < Away;
end;
$$ language plpgsql;
$$ language plpgsql;

select q5Check();
*/

-- Q6
/*
create or replace function q6Info(match Game.id%TYPE)
returns varchar as $$
DECLARE
    res varchar;
begin
    select CONCAT('Home: {Abb:',t1.abbreviation,', id:' ,g.idHomeTeam,'} Visitor: {Abb:',t2.abbreviation,', id:' ,g.idVisitorTeam,'}') into res
    from Game g, Team t1, Team t2
    where g.id = match and t1.id = g.idHomeTeam and t2.id = g.idVisitorTeam;

    return res;
end;
$$ language plpgsql;

select q6Info('22101005');

create or replace function q6(match GameDetail.idGame%TYPE, team GameDetail.idTeam%TYPE)
returns integer as $$
DECLARE
    points integer;
begin
    select sum(gd.points) into points
    from GameDetail gd
    where gd.idGame = match and gd.idTeam = team;

    return points;
end;
$$ language plpgsql;

select q6('22101005','1610612750');
*/

-- Q7
/*
create or replace function q7Check()
RETURNS void AS $$
DECLARE
    team1 integer := 0;
    team2 integer := 0;
    id_cursor cursor for select g.id, g.idHomeTeam, g.idVisitorTeam, g.ptsAway, g.ptsHome from Game g;

BEGIN
    for i in id_cursor LOOP
            team1 := q6(i.id, i.idHomeTeam);
            team2 := q6(i.id, i.idVisitorTeam);
            
            if team1 = i.ptsHome and team2 = i.ptsAway then
                raise notice 'Game %: Tout va bien', i.id;
            elsif team1 != i.ptsHome and team2 = i.ptsAway then
                raise notice 'Game %: Pb Equipe Home', i.id;
            elsif team1 = i.ptsHome and team2 != i.ptsAway then
                raise notice 'Game %: Pb Equipe Visitor', i.id;
            else
                raise notice 'Game %: Pb 2 Equipes', i.id;
            end if;
    end loop;
end;
$$ language plpgsql;

select q7Check()
*/

-- Q8
/*
Check vrai résultat des matchs
*/

-- Q9

create or replace function isBestAtHome(team Team.id%TYPE, an Game.season%type)
RETURNS bool AS $$
DECLARE
    Home integer := 0;
    Away integer := 0;
    id_cursor cursor for select g.id, g.homeTeamWins, g.idHomeTeam, g.idVisitorTeam
                         from Game g
                         where (team = g.idHomeTeam or team = g.idVisitorTeam) and season = an;

BEGIN
    for i in id_cursor LOOP
            if i.homeTeamWins and team = i.idHomeTeam then
                Home := Home + 1;
            end if;
            if not i.homeTeamWins and team = i.idVisitorTeam then
                Away := Away + 1;
            end if;
    end loop;
    return Home >= Away;
end;
$$ language plpgsql;
-- Q10
select isBestAtHome('1610612759',2021); -- Spurs Team -> True

-- Q11

create or replace function bestAtHome(an Game.season%type)
RETURNS table (v1 Team.id%TYPE, v2 Team.abbreviation%TYPE, v3 Team.nickname%TYPE, v4 Team.city%TYPE) AS $$
DECLARE
    id_cursor_2 cursor for select t.id, t.abbreviation, t.nickname, t.city
                         from Team t;

BEGIN
    for i in id_cursor_2 LOOP
            if isBestAtHome(i.id,an) then
                    v1 := i.id;
                    v2 := i.abbreviation;
                    v3 := i.nickname;
                    v4 := i.city;
                    return next;
            end if;
    end loop;
end;
$$ language plpgsql;
-- Q12

select bestAtHome(2021);
-- Q13

create or replace function q13(an Game.season%type)
RETURNS table (v1 Team.id%TYPE, v2 Team.abbreviation%TYPE, v3 Team.nickname%TYPE, v4 Team.city%TYPE) AS $$
DECLARE
    id_cursor cursor for select unique g.season
                         from Game g;
BEGIN
        for i in id_cursor LOOP
        
end;
$$ language plpgsql;