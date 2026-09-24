# Write your MySQL query statement below
Select 
    customer_id,
    Count(visit_id) AS count_no_trans
FROM 
    Visits
Where 
    visit_id NOT IN(
        Select 
            visit_id
            from transactions
)
Group By 
    customer_id;