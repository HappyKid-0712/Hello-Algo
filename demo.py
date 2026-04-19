import matplotlib.pyplot as plt

# 设置字体以支持中文显示（根据系统环境可调整字体名称，如 'SimHei'）
plt.rcParams['font.sans-serif'] = ['WenQuanYi Micro Hei', 'SimHei', 'DejaVu Sans']
plt.rcParams['axes.unicode_minus'] = False

# 模块名称与测试重点占比
labels = [
    'Auth & Profile\n(认证与个人中心)', 
    'Doc Management\n(文档管理系统)', 
    'Real-time Editor\n(实时编辑器)', 
    'Collaboration\n(协作与交互)'
]
sizes = [20, 25, 30, 25]  # 测试工作量/覆盖范围占比
colors = ['#ff9999', '#66b3ff', '#99ff99', '#ffcc99']
explode = (0, 0, 0.1, 0)  # 突出显示核心的“实时编辑器”模块

fig, ax = plt.subplots(figsize=(8, 6))
ax.pie(sizes, explode=explode, labels=labels, colors=colors, autopct='%1.1f%%',
        shadow=True, startangle=140)
ax.axis('equal')  # 确保饼图是正圆形

plt.title('Test Scope Distribution / 测试范围分布')
plt.tight_layout()
plt.savefig('test_scope.png', dpi=300) # 保存图表
plt.close()