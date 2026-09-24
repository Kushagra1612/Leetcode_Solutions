# Write your MySQL query statement below
Select s.year,s.price,p.product_name 
from Sales s
JOIN Product p
ON s.product_id=p.product_id;

-- SELECT 
--     p.product_name, 
--     s.year, 
--     s.price
-- FROM Sales s
-- JOIN Product p USING (product_id);

-- SELECT 
--     p.product_name, 
--     s.year, 
--     s.price
-- FROM Sales s, Product p
-- WHERE s.product_id = p.product_id;