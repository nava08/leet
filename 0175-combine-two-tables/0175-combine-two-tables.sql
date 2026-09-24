select P.firstName, P.lastName, A.city, A.state
from Person P
left join Address a on p.personId = a.personId;