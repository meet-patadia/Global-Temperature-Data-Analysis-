# Global-Temperature-Data-Analysis

Computational Analysis of Climate Change Patterns Using Statistical Methods and Data Visualization

Scientific Overview
This project implements a multi-dimensional analysis framework for global temperature datasets, employing temporal decomposition, century-scale comparative analysis, anomaly detection, and multi-variable correlation studies. The system processes raw climate data through a pipeline of statistical transformations to extract meaningful climate patterns.

Core Analytical Modules
1. Multi-Scale Temporal Decomposition
The codebase implements a hierarchical temporal analysis framework that processes data at multiple resolutions:
- Millennial-scale trends (1600-2015)
- Century-scale regimes (17th-20th century comparisons)
- Decadal oscillations (10-year moving windows)
- Annual cycles (monthly breakdowns)
- Intra-annual variability (seasonal anomalies)

2. Statistical Feature Extraction
- The analysis extracts 18 distinct climate features including:
- Temperature central tendencies (mean, median, mode)
- Dispersion metrics (variance, SD, IQR)
- Shape characteristics (skewness, kurtosis)
- Extreme value statistics (max/min records, return periods)
- Trend derivatives (slopes, inflection points)

3. Climate Regime Analysis
- The century-wise comparison module implements:
- Segmented linear regression with breakpoint detection
- Confidence interval estimation (95% CI)
- ANOVA for inter-century variance comparison
- Effect size measurement (Cohen's d)

Key Climate Regimes Identified:

Century	Baseline Temp	Warming Rate	Volatility
- 17th	8.21°C	+0.002°C/yr	Low
- 18th	8.57°C	+0.005°C/yr	Low
- 19th	9.03°C	+0.012°C/yr	Moderate
- 20th	10.11°C	+0.023°C/yr	High

4. Advanced Visualization Pipeline
- The system generates publication-quality visualizations through:
- GNUPlot scripting for temporal trend lines
- Comparative histogram matrices
- Heatmaps for seasonal patterns
- Box-whisker plots for century comparisons
- Uncertainty visualization with confidence bands

Technical Architecture
- The analysis pipeline follows a rigorous computational workflow:
- Data Ingestion Layer
- CSV parsing with robust error handling
- Missing data imputation (n = 1,243 records processed)
- Temporal alignment of heterogeneous records
- Computational Core
- Parallelized aggregation functions
- Memory-efficient streaming algorithms
- Numerical stability safeguards
- Analytical Modules
- Trend decomposition (additive/multiplicative models)
- Change point detection (PELT algorithm variant)
- Uncertainty propagation through Monte Carlo methods
