# עצים - STL, Templates, and Iterators

- **סטודנטית:** 314923822
- **אימייל:** morberger444@gmail.com
- 
עץ הוא גרף קשיר ללא מעגלים. במטלה זאת אתם מימשנו קונטיינר המייצג עץ k-ארי (עץ k-ארי הוא עץ שבו לכל קודקוד יש לכל היותר k ילדים. למשל, עץ בינארי הוא עץ 2-ארי.) גנרי שמכיל מפתחות מכל סוג (למשל מספרים, מחרוזות ומחלקות). 
המצב הדיפולטיבי של העץ הוא עץ בינארי (כלומר k=2). בשלב היצירה של הקונטיינר יש לציין את הסוג של המפתחות שהוא מכיל ואת מספר הילדים המקסימלי שיכול להיות לכל קודקוד. אם המספר הזה לא צוין, העץ יהיה עץ בינארי.
במטלה מימשתי את האיטרטורים הבאים:
1. איטרטור Pre-Order - איטרטור הסורק את העץ בצורה הבאה: צומת נוכחית -> תת עץ שמאלי -> תת עץ ימני (האיטרטור הזה עובד בצורה הזאת עבור עץ בינארי בלבד! עבור עץ כללי החזירו סריקת DFS רגילה שמתחילה מהשורש של העץ).
2. איטרטור Post-Order - איטרטור הסורק את העץ בצורה הבאה: תת עץ שמאלי -> תת עץ ימני -> צומת נוכחית (האיטרטור הזה עובד בצורה הזאת עבור עץ בינארי בלבד! עבור עץ כללי החזירו סריקת DFS רגילה שמתחילה מהשורש של העץ).
3. איטרטור In-Order  - איטרטור הסורק את העץ בצורה הבאה: תת עץ שמאלי -> צומת נוכחית -> תת עץ ימני (האיטרטור הזה עובד בצורה הזאת עבור עץ בינארי בלבד! עבור עץ כללי החזירו סריקת DFS רגילה שמתחילה מהשורש של העץ).
5. איטרטור BFS - סריקת העץ לרוחב (משמאלי לימין) (עובד על עץ כללי).
6. איטרטור DFS - סריקת העץ בעזרת אלגוריתם DFS (עובד על עץ כללי).
7. איטרטור Heap - הפיכת עץ בינארי לערימת מינימום.

שם הקונטיינר צריך להיות `tree`. יש להגדיר את המתודות הבאות:
1. המתודה `add_root` - הוספת השורש של העץ. המתודה מקבלת צומת כלשהו ושמה אותו בשורש העץ.
2. המתודה `add_sub_node` - הוספת ילד לאב. המתודה מקבלת צומת בעץ וצומת כלשהו ויוצרת בן עבור אותו צומת.
3. המתודות `begin_pre_order`, `end_pre_order`. המתודות מחזירות איטרטורים לצורך מעבור על העץ בשיטת Pre-Order.
4. המתודות `begin_post_order`, `end_post_order`. המתודות מחזירות איטרטורים לצורך מעבור על העץ בשיטת Post-Order.
5. המתודות `begin_in_order`, `end_in_order`. המתודות מחזירות איטרטורים לצורך מעבור על העץ בשיטת In-Order.
6. המתודות `begin_bfs_scan`, `end_bfs_scan`. המתודות מחזירות איטרטורים לצורך מעבור על העץ בעזרת האלגוריתם BFS.
7. המתודות `begin_dfs_scan`, `end_dfs_scan`. המתודות מחזירות איטרטורים לצורך מעבור על העץ בעזרת האלגוריתם DFS.
8. המתודה `myHeap`. המתודה הופכת עץ בינארי לערימת מינימום וחזירה איטרטורים עבור הערימה שהתקבלה.
9. יש לממש מפרק (Destructor) המוחק את כל העץ.

